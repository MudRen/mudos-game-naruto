// room9_s_r.c
// �ж�����, ��9��, �X�f��south

#include <ansi.h>

int isAreaPattern() { return 1; }

string getName() { return "�Фl[9��], �X�f[�n], �ũ��ǥծ� "; }

// icon�ˤl
private mapping getIcon()
{
    string color = BBLU+HIK;
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
