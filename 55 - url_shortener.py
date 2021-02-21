import hashlib

class URLShortener:
    def __init__(self):
        self.hash_to_key_map = dict()

    def shorten_url(self, url):
        hash = hashlib.md5(url.encode()).hexdigest()
        short_hash = hash[:6]
        self.hash_to_key_map[short_hash] = url
        return short_hash
    
    def restore(self, short_url):
        return self.hash_to_key_map[short_url]

u = URLShortener()

short_url = u.shorten_url("https://news.google.com")
print(short_url)
restored_url = u.restore(short_url)
print(restored_url)

short_url = u.shorten_url("https://docs.google.com")
print(short_url)
restored_url = u.restore(short_url)
print(restored_url)
