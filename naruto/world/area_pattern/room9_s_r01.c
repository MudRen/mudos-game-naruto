// room9_s_r.c
// �ж�����, ��9��, �X�f��south

#include <ansi.h>

int isAreaPattern() { return 1; }

string getName() { return "�Фl[9��], �X�f[�n], �ũ��~���C���H�� "; }

private string getRandomColor()
{
    string *sample = ({
        BBLU+HIK,
        BBLU+HIW,
        BBLU+HIR,
        BBLU+HIG,
        BBLU+HIB,
        BBLU+HIM,
        BBLU+HIC,
        BBLU+HIY,
    });
    return sample[random(sizeof(sample))];
}


// icon�ˤl
private mapping getIcon()
{
    string color = getRandomColor();
    mapping icon = ([   
        0: ({ color +"��"NOR, color +"��"NOR, color +"��"NOR }),
        1: ({ color +"��"NOR, color +"  "NOR, color +"��"NOR }),
        2: ({ color +"��"NOR, color +"�C"NOR, color +"��"NOR }),
    ]);

    return icon;
}

// block�]�w
private mapping getBlock()
{
    mapping block = ([
        0: ({1, 1, 1}),
        1: ({1, 0, 1}),
        2: ({1, 0, 1}),
    ]);

    return block;
}

mapping getMapStyle()
{
    mapping style = ([
        "icon": getIcon(),
        "block": getBlock(),
    ]);

    return style;
}
