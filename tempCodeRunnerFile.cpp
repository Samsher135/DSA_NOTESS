int num = 0,i=0;
        while(x != 0){
            int lastbit = x&1;
            num = (lastbit * pow(10,i)) + num;
            x = x>>1;
            i++;
        }