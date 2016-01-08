//
// Created by robin on 1/8/16.
//

#ifdef ARD_UTILS_DELAYMS
void ArdUtils::delayMs(unsigned ms)
{
    for (unsigned i = 0; i < ms; i++) {
        delayMicroseconds(1000);
    }
}
#endif


#ifdef ARD_UTILS_UTF8
byte ArdUtils::_utf8ToAscii(byte ascii, byte& c1)
{
    if ( ascii<128 )   // Standard ASCII-set 0..0x7F handling
    {   c1=0;
        return( ascii );
    }

    // get previous input
    byte last = c1;   // get last char
    c1=ascii;         // remember actual character

    switch (last)     // conversion depnding on first UTF8-character
    {   case 0xC2: return  (ascii);  break;
        case 0xC3: return  (ascii | 0xC0);  break;
        case 0x82: if(ascii==0xAC) return(0x80);       // special case Euro-symbol
    }

    return  (0);                                     // otherwise: return zero, if character has to be ignored
}

void ArdUtils::utf8ToAscii(char* s)
{
    byte c1 = 0;
    int k=0;
    byte c;
    unsigned len = strlen(s);
    for (unsigned i=0; i<len; i++)
    {
        c = ArdUtils::_utf8ToAscii(s[i], c1);
        if (c!=0)
            s[k++]=c;
    }
    s[k]=0;
}
#endif