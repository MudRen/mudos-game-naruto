// green81_r_01.c
// ��a, �K�Q�@��, �H��

#include <ansi.h>

int isAreaPattern() { return 1; }

string getName() { return "��a[81��], �˦��H�� "; }

private string getSample()
{
    string *sample = ({ "  ", GRN"��"NOR, "  ", YEL"��"NOR, "  ", HIG"��"NOR });
    return sample[random(sizeof(sample))];
}

// icon�ˤl
private mapping getIcon()
{
    mapping icon = ([   
        0: ({ getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample() }),
        1: ({ getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample() }),
        2: ({ getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample() }),
        3: ({ getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample() }),
        4: ({ getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample() }),
        5: ({ getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample() }),
        6: ({ getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample() }),
        7: ({ getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample() }),
        8: ({ getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample(), getSample() }),
    ]);

    return icon;
}

mapping getMapStyle()
{
    mapping style = ([
        "icon": getIcon(),
    ]);

    return style;
}
