// room9_s_01.c
// �ж�����, ��9��, �X�f��south, �s��1

#include <ansi.h>

int isAreaPattern() { return 1; }

string getName() { return "�Фl[9��], �X�f[�n], �ũ��G���� "; }

// icon�ˤl
private mapping getIcon()
{
    mapping icon = ([	
        0: ({ BBLU+HIR"��"NOR, BBLU+HIR"��"NOR, BBLU+HIR"��"NOR }),
        1: ({ BBLU+HIR"��"NOR, BBLU+HIR"  "NOR, BBLU+HIR"��"NOR }),
        2: ({ BBLU+HIR"��"NOR, BBLU+HIR"�C"NOR, BBLU+HIR"��"NOR }),
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