/*
Given a string IP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.
*/
class Solution {
public:
    string validIPAddress(string IP) {
        return validIPv4(IP)? "IPv4" : validIPv6(IP)? "IPv6" : "Neither";
    }
private:
    bool validIPv4(string IP){
        if(count(IP.begin(), IP.end(), '.') != 3) return false;
        vector<string> parts = split(IP, '.');
        if(parts.size() != 4) return false;
        for(string part : parts){
            if(part.empty() || part.length() > 3 || part.size() > 1 && part[0] == '0') return false;
            for(char& c : part){
                if(!isdigit(c)) return false;
            }
            if(stoi(part) > 255) return false;
        }
        return true;
    }
    bool validIPv6(string IP){
        if(count(IP.begin(), IP.end(), ':') != 7) return false;
        vector<string> parts = split(IP, ':');
        if(parts.size() != 8) return false;
        for(string part : parts){
            if(part.empty() || part.length() > 4) return false;
            for(char& c : part){
                if(!isdigit(c) && (!isalpha(c) || toupper(c) > 'F')) return false;
            }
        }
        return true;
    }
    vector<string> split(string s, char c){
        string delim = to_string(c);
        size_t end = s.find(c), start = 0;
        vector<string> res;
        while(end != std::string::npos){
            res.push_back(s.substr(start, end - start));
            start = end + 1;
            end   = s.find(c, start);
        }
        res.push_back(s.substr(start));
        return res;
    }
};