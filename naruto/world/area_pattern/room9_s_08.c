// room9_s_01.c
// �ж�����, ��9��, �X�f��south, �s��1

#include <ansi.h>

int isAreaPattern() { return 1; }

string getName() { return "�Фl[9��], �X�f[�n], �ũ��G�C�� "; }

// icon�ˤl
private mapping getIcon()
{
    mapping icon = ([	
        0: ({ BBLU+HIC"��"NOR, BBLU+HIC"��"NOR, BBLU+HIC"��"NOR }),
        1: ({ BBLU+HIC"��"NOR, BBLU+HIC"  "NOR, BBLU+HIC"��"NOR }),
        2: ({ BBLU+HIC"��"NOR, BBLU+HIC"�C"NOR, BBLU+HIC"��"NOR }),
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