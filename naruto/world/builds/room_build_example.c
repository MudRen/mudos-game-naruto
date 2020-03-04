/*
3*3����� room build�G
   �j  �j  �j
     ���E��
   �j�E��E�j
     ���E��
   �j  �j  �j

�i - ��
�E - �X�f
�� - ���a�إ�build�ɭn���ߪ��I
�j - �ˬd�I�A�إ�build�ɭn�ˬd�A�H����P�䥦build�۳s
*/

#include <ansi.h>

// �ж����ؿv��
int isRoomBuilding() { return 1; }

string getCheckPointsPosition() { return "(-2,-2)"; }

// ���o�ˬd�I (�n�]�t�ؿv����)
string* getCheckPoints()
{
    string *check = 
        ({ "10101",
           "01110",
           "11111",
           "01110",
           "10101",
        });
    return check;
}

// ����a
string* toOccupy()
{
    string *occupy =
        ({ "00000",
           "01110",
           "01110",
           "01110",
           "00000",
        });
    return occupy;
}

// wall
string* getWall()
{
    string *wall =
        ({ "00000",
           "01010",
           "00100",
           "01010",
           "00000",
        });
    return wall;
}

private string getSample()
{
    string *sample = ({ "  ", GRN"��"NOR, "  ", YEL"��"NOR, "  ", HIG"��"NOR });
    return sample[random(sizeof(sample))];
}

int getStyleCount() { return 5; }

mapping getStyle(int type)
{
    mapping style = ([]);
    
    if( type == 1 ) {
        style = 
            ([ 0: ({ getSample(), getSample(), getSample(), getSample(), getSample() }),
               1: ({ getSample(), "�z", "�C", "�{", getSample() }),
               2: ({ getSample(), "�C", "  ", "�C", getSample() }),
               3: ({ getSample(), "�|", "�C", "�}", getSample() }),
               4: ({ getSample(), getSample(), getSample(), getSample(), getSample() }),
            ]);
    } else if( type == 2 ) {
        style = 
            ([ 0: ({ getSample(), getSample(), getSample(), getSample(), getSample() }),
               1: ({ getSample(), "��", "�C", "��", getSample() }),
               2: ({ getSample(), "�C", "  ", "�C", getSample() }),
               3: ({ getSample(), "��", "�C", "��", getSample() }),
               4: ({ getSample(), getSample(), getSample(), getSample(), getSample() }),
            ]);
    } else if( type == 3 ) {
        style = 
            ([ 0: ({ getSample(), getSample(), getSample(), getSample(), getSample() }),
               1: ({ getSample(), "��", "�w", "��", getSample() }),
               2: ({ getSample(), "�x", "  ", "�x", getSample() }),
               3: ({ getSample(), "��", "�w", "��", getSample() }),
               4: ({ getSample(), getSample(), getSample(), getSample(), getSample() }),
            ]);
    } else if( type == 4 ) {
        style = 
            ([ 0: ({ getSample(), getSample(), getSample(), getSample(), getSample() }),
               1: ({ getSample(), "��", "��", "��", getSample() }),
               2: ({ getSample(), "��", "  ", "��", getSample() }),
               3: ({ getSample(), "��", "��", "��", getSample() }),
               4: ({ getSample(), getSample(), getSample(), getSample(), getSample() }),
            ]);
    } else if( type == 5 ) {
        style = 
            ([ 0: ({ getSample(), getSample(), getSample(), getSample(), getSample() }),
               1: ({ getSample(), "�i", REV"�g"NOR, "�i", getSample() }),
               2: ({ getSample(), "�k", "  ", REV"�o"NOR, getSample() }),
               3: ({ getSample(), "�i", "�c", "�i", getSample() }),
               4: ({ getSample(), getSample(), getSample(), getSample(), getSample() }),
            ]);        
    } else { // for destruct
        style = 
            ([ 0: ({ getSample(), getSample(), getSample(), getSample(), getSample() }),
               1: ({ getSample(), getSample(), getSample(), getSample(), getSample() }),
               2: ({ getSample(), getSample(), getSample(), getSample(), getSample() }),
               3: ({ getSample(), getSample(), getSample(), getSample(), getSample() }),
               4: ({ getSample(), getSample(), getSample(), getSample(), getSample() }),
            ]);
    }

    return style;
}

int getTitleLength() { return 1; }

string getTitlePosition(int index)
{
    if( index == 1 ) return "(2,2)";
    return 0;
}

mapping getExitPosition()
{
    mapping exits = ([
        "north": "(2,1)",
        "east": "(3,2)",
        "south": "(2,3)",
        "west": "(1,2)",
    ]);
    return exits;
}

// �ئnbuild��A�|�I�s�o��
// ��K�]�w area �i�H�ϥΪ��\��
int postCondition(object build)
{
}