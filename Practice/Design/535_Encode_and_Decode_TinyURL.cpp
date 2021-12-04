class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code;
        while(!url2code.count(longUrl)){
            random_shuffle(charset.begin(), charset.end());
            code = charset.substr(0,6);
            if(code2url.find(code) == code2url.end()){
                code2url[code] = longUrl;
                url2code[longUrl] = code;
            }
        }
        return "http://tinyurl.com/" + code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
		// if (shortUrl.size() != 25 || !code2url.count(shortUrl.substr(19, 6)))
		// 	return "";
		// return code2url[shortUrl.substr(19, 6)];
        int p = shortUrl.find_last_of("/");
        return code2url[shortUrl.substr(p + 1)];
    }
private:
    unordered_map<string, string> code2url, url2code;
    string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
};