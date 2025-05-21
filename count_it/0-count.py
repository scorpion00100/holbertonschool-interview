#!/usr/bin/python3
"""
Module for counting word occurrences in Reddit post titles
"""
import requests


def count_words(subreddit, word_list, after=None, word_counts=None):
    """
    Recursively queries the Reddit API and counts occurrences of keywords
    in post titles.
    """
    # Initialize word_counts on first call
    if word_counts is None:
        word_counts = {}
        for word in word_list:
            word_lower = word.lower()
            if word_lower in word_counts:
                continue
            word_counts[word_lower] = 0

    # Base case: if word_list is empty, print nothing and return
    if not word_list:
        return None

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "linux:0-count:v1.0 (by /u/yourusername)"}
    params = {"limit": 100}
    if after:
        params["after"] = after

    response = requests.get(url, headers=headers, params=params, allow_redirects=False)

    if response.status_code != 200:
        return None

    data = response.json()
    posts = data.get("data", {}).get("children", [])

    for post in posts:
        title = post.get("data", {}).get("title", "").lower()
        for word in title.split():
            clean_word = ""
            for char in word:
                if char.isalnum():
                    clean_word += char
                else:
                    clean_word += " "
            
            for target_word in word_counts:
                for part in clean_word.split():
                    if part == target_word:
                        word_counts[target_word] += 1

    after = data.get("data", {}).get("after")
    if after:
        return count_words(subreddit, word_list, after, word_counts)
    else:
        sorted_counts = sorted(
            [(k, v) for k, v in word_counts.items() if v > 0],
            key=lambda x: (-x[1], x[0])
        )
        
        for word, count in sorted_counts:
            print(f"{word}: {count}")
        
        return None
