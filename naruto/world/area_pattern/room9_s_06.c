// room9_s_01.c
// �ж�����, ��9��, �X�f��south, �s��1

#include <ansi.h>

int isAreaPattern() { return 1; }

string getName() { return "�Фl[9��], �X�f[�n], �ũ��G�Ů� "; }

// icon�ˤl
private mapping getIcon()
{
    mapping icon = ([	
        0: ({ BBLU+HIB"��"NOR, BBLU+HIB"��"NOR, BBLU+HIB"��"NOR }),
        1: ({ BBLU+HIB"��"NOR, BBLU+HIB"  "NOR, BBLU+HIB"��"NOR }),
        2: ({ BBLU+HIB"��"NOR, BBLU+HIB"�C"NOR, BBLU+HIB"��"NOR }),
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