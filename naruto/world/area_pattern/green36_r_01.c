// green36_r_01.c
// ��a, �T�Q����, �H��

#include <ansi.h>

int isAreaPattern() { return 1; }

string getName() { return "��a[36��], �˦��H�� "; }

private string getSample()
{
    string *sample = ({ "  ", GRN"��"NOR, "  ", YEL"��"NOR, "  ", HIG"��"NOR });
    return sample[random(sizeof(sample))];
}

// icon�ˤl
private mapping getIcon()
{
    mapping icon = ([   
        0: ({ getSample(), getSample(), getSample(), getSample(), getSample(), getSample() }),
        1: ({ getSample(), getSample(), getSample(), getSample(), getSample(), getSample() }),
        2: ({ getSample(), getSample(), getSample(), getSample(), getSample(), getSample() }),
        3: ({ getSample(), getSample(), getSample(), getSample(), getSample(), getSample() }),
        4: ({ getSample(), getSample(), getSample(), getSample(), getSample(), getSample() }),
        5: ({ getSample(), getSample(), getSample(), getSample(), getSample(), getSample() }),
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
