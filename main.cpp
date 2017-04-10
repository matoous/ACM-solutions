#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
#define piic pair<pii, char>
#define x .first.first
#define y .first.second

using namespace std;

vector<piic> boxes;
short sx, sy, bc, px, py, hm;
char lat;
string s;

struct {
    bool operator()(piic a, piic b)
    {
        if(a x == b x)
            return a y < b y;
        return a x < b x;
    }
} byX;

struct {
    bool operator()(piic a, piic b)
    {
        if(a x == b x)
            return a y > b y;
        return a x < b x;
    }
} byXr;

struct {
    bool operator()(piic a, piic b)
    {
        if(a y == b y)
            return a x < b x;
        return a y < b y;
    }
} byY;

struct {
    bool operator()(piic a, piic b)
    {
        if(a y == b y)
            return a x > b x;
        return a y < b y;
    }
} byYr;

void printBoxes(){
    for(int i = 0; i < boxes.size(); i++){
        if(i == 0)
            printf("(%hi,%hi)", boxes[i]x, boxes[i]y);
        else
            printf(" (%hi,%hi)", boxes[i]x, boxes[i]y);
    }
    printf(".\n");
}

void moveLeft(int hmch){
    sort(boxes.begin(), boxes.end(), byXr);
    int mir = 1, nir = 1;
    for(int i = 1; i < boxes.size(); i++){
        if(boxes[i]x == boxes[i-1]x){
            nir++;
            mir = nir > mir ? nir : mir;
        }
        else
            nir = 1;
    }
    hmch = sy - mir < hmch ? sy - mir : hmch;
    for(int i = 0; i < boxes.size(); i++)
        if(boxes[i]y >= sy - hmch) boxes[i]y = sy - hmch -1;
    for(int i = 1; i < boxes.size(); i++){
        int newy = boxes[i - 1]y - 1;
        while(i < boxes.size() && boxes[i-1]x == boxes[i]x){
            boxes[i]y = boxes[i]y < newy ? boxes[i]y : newy--;
            i++;
        }
    }
}

void moveRight(int hmch){
    sort(boxes.begin(), boxes.end(), byX);
    int mir = 1, nir = 1;
    for(int i = 1; i < boxes.size(); i++){
        if(boxes[i]x == boxes[i-1]x){
            nir++;
            mir = nir > mir ? nir : mir;
        }
        else
            nir = 1;
    }
    hmch = sy - mir < hmch ? sy - mir : hmch;
    for(int i = 0; i < boxes.size(); i++)
        if(boxes[i]y < hmch) boxes[i]y = hmch;
    for(int i = 1; i < boxes.size(); i++){
        int newy = boxes[i - 1]y + 1;
        while(i < boxes.size() && boxes[i-1]x == boxes[i]x){
            boxes[i]y = boxes[i]y > newy ? boxes[i]y : newy++;
            i++;
        }
    }
}

void moveDown(int hmch){
    sort(boxes.begin(), boxes.end(), byY);
    int mir = 1, nir = 1;
    for(int i = 1; i < boxes.size(); i++){
        if(boxes[i]y == boxes[i-1]y){
            nir++;
            mir = nir > mir ? nir : mir;
        }
        else
            nir = 1;
    }
    hmch = sx - mir < hmch ? sx - mir : hmch;
    for(int i = 0; i < boxes.size(); i++)
        if(boxes[i]x < hmch) boxes[i]x = hmch;
    for(int i = 1; i < boxes.size(); i++){
        int newx = boxes[i - 1]x + 1;
        while(i < boxes.size() && boxes[i-1]y == boxes[i]y){
            boxes[i]x = boxes[i]x > newx ? boxes[i]x : newx++;
            i++;
        }
    }
}

void moveUp(int hmch){
    sort(boxes.begin(), boxes.end(), byYr);
    int mir = 1, nir = 1;
    for(int i = 1; i < boxes.size(); i++){
        if(boxes[i]y == boxes[i-1]y){
            nir++;
            mir = nir > mir ? nir : mir;
        }
        else
            nir = 1;
    }
    hmch = sx - mir < hmch ? sx - mir : hmch;
    for(int i = 0; i < boxes.size(); i++)
        if(boxes[i]x >= sx - hmch) boxes[i]x = sx - hmch - 1;
    for(int i = 1; i < boxes.size(); i++){
        int newx = boxes[i - 1]x - 1;
        while(i < boxes.size() && boxes[i-1]y == boxes[i]y){
            boxes[i]x = boxes[i]x < newx ? boxes[i]x : newx--;
            i++;
        }
    }
}

int main(){
    int hababa = 1;
    while(scanf("%hi %hi", &sx, &sy) && sx != 0){
        scanf("%hi", &bc);
        lat = 'A';
        for(int i = 0; i < bc; i++){
            scanf("%hi %hi", &px, &py);
            boxes.push_back(piic(pii(px, py),lat++));
        }
        while(cin >> s && s.compare("done")){
            scanf("%hi", &hm);
            if(!s.compare("left")) moveLeft(hm);
            else if(!s.compare("right")) moveRight(hm);
            else if(!s.compare("up")) moveUp(hm);
            else moveDown(hm);
        }
        printf("Data set %d ends with boxes at locations ", hababa++);
        sort(boxes.begin(), boxes.end(), byX);
        printBoxes();
        boxes.clear();
    }
    return 0;
}