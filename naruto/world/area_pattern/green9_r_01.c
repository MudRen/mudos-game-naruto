// green9_r_01.c
// ��a, �E��, �H��

#include <ansi.h>

int isAreaPattern() { return 1; }

string getName() { return "��a[9��], �˦��H�� "; }

private string getSample()
{
    string *sample = ({ "  ", GRN"��"NOR, "  ", YEL"��"NOR, "  ", HIG"��"NOR });
    return sample[random(sizeof(sample))];
}

// icon�ˤl
private mapping getIcon()
{
    mapping icon = ([	
        0: ({ getSample(), getSample(), getSample() }),
        1: ({ getSample(), getSample(), getSample() }),
        2: ({ getSample(), getSample(), getSample() }),
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