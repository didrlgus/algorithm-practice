// 매칭 점수
#include<bits/stdc++.h>
using namespace std;
struct Page {
    int idx,basic,link;
    double score;
};
bool cmp(Page& p1,Page& p2) {
    if(p1.score==p2.score) return p1.idx<p2.idx;
    return p1.score>p2.score;
}
int solution(string word, vector<string> pages) {
    int w_size=(int)word.size();
    map<string,int> page_hash;
    vector<Page> page_list;
    transform(word.begin(),word.end(),word.begin(),::tolower);
    for(int i=0;i<(int)pages.size();i++) {
        string& s=pages[i];
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int left=0,right=0,mid=0;
        while(mid<=left) {
            left=s.find("<meta",left+1);
            right=s.find(">",left);
            mid=s.rfind("https://",right);
        }
        right=s.find("\"",mid);
        string url=s.substr(mid,right-mid);
        page_hash[url]=i;
        left=s.find("<body>",right);
        int basic=0;
        for(int start=left;;) {
            start=s.find(word,start+1);
            if(start==string::npos) break;
            if(!isalpha(s[start-1])&&!isalpha(s[start+w_size])) {
                basic++;
                start+=w_size;
            }
        }
        int link=0;
        for(int start=left;;) {
            start=s.find("<a href",start+1);
            if(start==string::npos) break;
            link++;
        }
        page_list.push_back({i,basic,link,(double)basic});
    }
    for(int i=0;i<(int)pages.size();i++) {
        string& s=pages[i];
        for(int left=0,right=0;;) {
            left=s.find("<a href",right);
            if(left==string::npos) break;
            left=s.find("https://",left);
            right=s.find("\"",left);
            string link_url=s.substr(left,right-left);
            map<string,int>::iterator it=page_hash.find(link_url);
            if(it!=page_hash.end()) page_list[it->second].score+=(double)page_list[i].basic/page_list[i].link;
        }
    }
    sort(page_list.begin(),page_list.end(),cmp);
    return page_list.begin()->idx;
}

int main() {
    string word="muzi";
    vector<string> pages={
        "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", 
        "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"
        };
    vector<string> pages2={
        "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"
    };
    printf("%d\n",solution(word,pages));
    return 0;
}