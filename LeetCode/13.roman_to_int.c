int romanToInt(char *s)
{
    int res = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'I')
        {
            if (s[i + 1] == 'V')
            {
                res += 4;
                i++;
                continue;
            }
            if (s[i + 1] == 'X')
            {
                res += 9;
                i++;
                continue;
            }
        }
        if (s[i] == 'X')
        {
            if (s[i + 1] == 'L')
            {
                res += 40;
                i++;
                continue;
            }
            if (s[i + 1] == 'C')
            {
                res += 90;
                i++;
                continue;
            }
        }
        if (s[i] == 'C')
        {
            if (s[i + 1] == 'D')
            {
                res += 400;
                i++;
                continue;
            }
            if (s[i + 1] == 'M')
            {
                res += 900;
                i++;
                continue;
            }
        }
        switch (s[i])
        {
        case 'I':
            res += 1;
            break;
        case 'V':
            res += 5;
            break;
        case 'X':
            res += 10;
            break;
        case 'L':
            res += 50;
            break;
        case 'C':
            res += 100;
            break;
        case 'D':
            res += 500;
            break;
        case 'M':
            res += 1000;
            break;
        default:
            break;
        }
    }
    return res;
}