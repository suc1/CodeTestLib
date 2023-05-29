string timeConversion(string s) {
    int hour, minute, second;
    char buf[16];
    buf[0]='\0';
    
    /*
    std::istringstream iss(str);
    int a, b;
    iss >> a >> b;
    */
    sscanf(s.c_str(), "%d:%d:%d%s", &hour, &minute, &second, buf);
    if(buf[0]=='P') {
        //12:00:00PM        12:00:00
        if(hour!=12) hour += 12;        
    }
    else {
        //12:00:00AM        00:00:00
        if(hour==12) hour=0;
    }
    
    sprintf(buf, "%02d:%02d:%02d", hour, minute, second);
    return buf;
}
