//use map to record the encode and decode result
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(!encodeMp.count(longUrl)){
            string shortUrl = base + to_string(encodeMp.size());
            encodeMp[longUrl] = shortUrl;
            decodeMp[shortUrl] = longUrl;
        }
        return encodeMp[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decodeMp[shortUrl];
    }
private:
    unordered_map<string,string> encodeMp;
    unordered_map<string,string> decodeMp;
    string base = "https://tinyurl.com/";
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));