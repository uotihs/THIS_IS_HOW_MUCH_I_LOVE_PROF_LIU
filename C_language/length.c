void init(int length[3]) {
    for(int i=0;i<3;i++)
        length[i]=0;
    /* add your code */
}
void add(int length[3], int i) {
    int sum1 = 0;
    sum1+= length[0]*36+length[1]*12+length[2];
    sum1+=i;

    length[0] = sum1/36;
    length[1] = (sum1%36)/12;
    length[2] = sum1%12;
    /* add your code */
}
void sum(int lengtha[3], int lengthb[3], int lengthc[3]) {

    int ans = lengtha[0]*36+lengtha[1]*12+lengtha[2];
    ans += lengthb[0]*36+lengthb[1]*12+lengthb[2];

    lengthc[0] = ans/36;
    lengthc[1] = (ans%36)/12;
    lengthc[2] = ans%12;
    
    /* add your code */
}
void diff(int lengtha[3], int lengthb[3], int lengthc[3]) {
    int ans = lengtha[0]*36+lengtha[1]*12+lengtha[2];
    ans -= lengthb[0]*36+lengthb[1]*12+lengthb[2];

    lengthc[0] = ans/36;
    lengthc[1] = (ans%36)/12;
    lengthc[2] = ans%12;
    
    /* add your code */
}