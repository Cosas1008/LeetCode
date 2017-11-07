bool judgeCircle(char* moves) {
    int circle[2] = {0};
    while(*moves){
        switch(*moves){
            case 'L':
                circle[0] += 1;
                break;
            case 'R':
                circle[0] -= 1;
                break;
            case 'U':
                circle[1] += 1;
                break;
            case 'D':
                circle[1] -= 1;
                break;
        }
        *moves++;
    }
    //printf("%d %d", circle[0], circle[1]);
    return circle[0]==0 && circle[1]==0;
}