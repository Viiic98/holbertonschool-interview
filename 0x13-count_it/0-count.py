#!/usr/bin/python3
""" Reddit API """
import requests


def check_title(title, i, word_dict, word_list):
    """ Check word in title """
    if i < len(title):
        if title[i] in word_list:
            if title[i] in word_dict:
                word_dict[title[i]] += 1
            else:
                word_dict[title[i]] = 1
        word_dict = check_title(title, i + 1, word_dict, word_list)
    return word_dict


def check_articles(all_articles, word_dict, word_list):
    """ Check all articles in list and take its titles """
    if all_articles:
        title = all_articles[0].get('data').get('title')
        title = title.lower()
        word_dict = check_title(title.split(), 0, word_dict, word_list)
        all_articles.pop(0)
        if len(all_articles) > 0:
            check_articles(all_articles, word_dict, word_list)
    return word_dict


def get_articles(subreddit, word_dict, word_list, after=""):
    """ Make request to hot articles """
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    url += "?limit=100&after={}".format(after)
    r = requests.get(url, allow_redirects=False)
    if r.status_code == 200:
        all_articles = r.json().get('data').get('children')
        word_dict = check_articles(all_articles, word_dict, word_list)
        after = r.json().get('after')
        word_dict = get_articles(subreddit, word_dict, word_list, after)
    return word_dict


def print_words(words, i):
    """ Print words """
    if i < len(words):
        print("{}: {}".format(words[i][0], words[i][1]))
        print_words(words, i + 1)


def count_words(subreddit, word_list):
    """ recursive function that queries the Reddit API """
    word_dict = get_articles(subreddit, {}, word_list, "")
    sort = sorted(word_dict.items(), key=lambda item: item[1], reverse=True)
    print_words(sort, 0)
