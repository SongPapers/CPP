#include<iostream>
using namespace std;

// 友元friend 一个函数或类，作为了另一个类的友元，那么这个函数可以直接访问另一个私有数据
// 重要用在运算符重载上

// 普通全局变量函数作为类的友元
class Room{
friend void visiting01(Room &room);
private:
    string bedRoom; // 卧室
public:
    string setingRoom; // 客厅
public:
Room(string bedRoom, string setingRoom){
    this->bedRoom = bedRoom;
    this->setingRoom = setingRoom;
}
};

// 普通全局变量
void visiting01(Room &room){
    cout << "访问了" << room.setingRoom << endl;
    cout << "访问量" << room.bedRoom << endl;
}

// 类的某个成员函数 作为另一个类的友元

class Room1;    // 类的向前声明
class goodGay{
public:
    void visiting01(Room1 &room);
    void visiting02(Room1 &room);
};

class Room1{
    friend void goodGay::visiting02(Room1 &room);
private:
    string bedRoom; // 卧室
public:
    string setingRoom; // 客厅
public:
    Room1(string bedRoom, string setingRoom){
        this->bedRoom = bedRoom;
        this->setingRoom = setingRoom;
    }
};

void goodGay::visiting01(Room1 &room){
    cout << "访问了" << room.setingRoom << endl;
    // cout << "访问了" << room.bedRoom << endl;
}

void goodGay::visiting02(Room1 &room){
    cout << "好基友访问了" << room.setingRoom << endl;
    cout << "好基友访问了" << room.bedRoom << endl;
}


// 整个类作为 另一个类的友元

class Room2;
class goodGay2{
public:
    void visiting01(Room2 &room);
    void visiting02(Room2 &room);
};

class Room2{
    friend class goodGay2;
private:
    string bedRoom;
public:
    string setingRoom;
public:
    Room2(string bedRoom, string setRoom){
        this->bedRoom = bedRoom;
        this->setingRoom = setingRoom;
    }
};

void goodGay2::visiting01(Room2 &room){
    cout << "访问了" << room.setingRoom << endl;
    cout << "访问了" << room.bedRoom << endl;
}

void goodGay2::visiting02(Room2 &room){
    cout << "好基友访问了" << room.setingRoom << endl;
    cout << "好基友访问了" << room.bedRoom << endl;
}

// 友元案列（遥控器类）

// 遥控器作为TV的友元
class TV;
class Remote{
private:
    TV *p;
public:
    Remote(TV *p);
    void offOrOn(void);
    void upVolume(void);
    void downVolume(void);
    void upChannel(void);
    void downChannel(void);
    void showTv(void);
    // 操作遥控器
    void setChannel(int channel);
};


class TV{
    friend class Remote;
    enum {OFF, ON};
    enum {minVol, maxVol=10};
    enum {minChan, maxChan=25};
private:
    int state;
    int volume;
    int channel;
public:
    TV(){
        state = OFF;
        volume = minVol;
        channel = minChan;
    }
    void offOrOn(void);
    void upVolume(void);
    void downVolume(void);
    void upChannel(void);
    void downChannel(void);
    void showTv(void);
};

// 构造函数
Remote::Remote(TV *p){
    this->p = p;
}
void Remote::offOrOn(){
    p->offOrOn();
}

void Remote::upVolume(){
    p->upVolume();
}
void Remote::downVolume(){
    p->downVolume();
}
void Remote::upChannel(){
    p->upChannel();
}
void Remote::downChannel(){
    p->downChannel();
}
void Remote::showTv(){
    p->showTv();
}
void Remote::setChannel(int channel){
    if(channel>=TV::minChan && channel<=TV::maxChan){
        p->channel = channel;
    }
    else{
        cout << "频道" << channel << "不在有效范围内" << endl;
    }
}


void TV::offOrOn(){
    state = (state == OFF ? ON : OFF);
}

void TV::upVolume(){
    if(volume==maxVol){
        cout << "音量已经最大" << endl;
        return;
    }
    volume++;
}
void TV::downVolume(){
    if(volume==minVol){
        cout << "音量已经最小" << endl;
        return;
    }
    volume--;
}
void TV::upChannel(){
    if(channel==maxChan){
        cout << "频道已经最大" << endl;
        return;
    }
    channel++;
}
void TV::downChannel(){
    if(channel==minChan){
        cout << "频道已经最小" << endl;
        return;
    }
    channel--;
}
void TV::showTv(){
    cout << "当前电视机的状态：" << (state==OFF?"关":"开") << endl;
    cout << "当前电视机的音量：" << volume << endl;
    cout << "当前电视机的频道：" << channel << endl;
}



int main(){
    Room room("卧室", "客厅");
    visiting01(room);

    Room1 room1("卧室", "客厅");
    goodGay ob;
    ob.visiting01(room1);
    ob.visiting02(room1);

    Room2 room2("卧室", "客厅");
    goodGay2 ob2;
    ob2.visiting01(room2);
    ob2.visiting02(room2);

    TV tv;
    tv.offOrOn();
    tv.upVolume();
    tv.upChannel();
    tv.showTv();

    Remote re(&tv);
    re.offOrOn();
    re.upVolume();
    re.upVolume();
    re.setChannel(10);
    re.showTv();

    return 0;
}
