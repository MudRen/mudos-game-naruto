/*
3*3����� room build�G
   �j  �j
     ��
   �j  �j

�� - ���a�إ�build�ɭn���ߪ��I
�j - �ˬd�I�A�إ�build�ɭn�ˬd�A�H����P�䥦build�۳s
*/

#include <ansi.h>

// �ж����ؿv��
int isRoomBuilding() { return 1; }

string getName() { return "���� (1*1) - �|��X�f"; }

string getCheckPointsPosition() { return "(-1,-1)"; }

// ���o�ˬd�I (�n�]�t�ؿv����)
string* getCheckPoints()
{
    string *check = 
           ({ "111",
              "111",
              "111",
           });
    return check;
}

// ����a
string* toOccupy()
{
    string *occupy =
        ({ "000",
           "010",
           "000",
        });
    return occupy;
}

// wall
string* getWall()
{
    string *wall =
        ({ "000",
           "000",
           "000",
        });
    return wall;
}

private string getSample()
{
    string *sample = ({ "  ", GRN"��"NOR, "  ", YEL"��"NOR, "  ", HIG"��"NOR });
    return sample[random(sizeof(sample))];
}

int getStyleCount() { return 1; }

mapping getStyle(int type)
{
    mapping style = ([]);
    
    if( type == 1 ) {
        style = 
            ([ 0: ({ getSample(), getSample(), getSample() }),
               1: ({ getSample(), BYEL+HIB"��"NOR, getSample() }),
               2: ({ getSample(), getSample(), getSample() }),
            ]);
    } else { // for destruct
        style = 
            ([ 0: ({ getSample(), getSample(), getSample() }),
               1: ({ getSample(), getSample(), getSample() }),
               2: ({ getSample(), getSample(), getSample() }),
            ]);
    }

    return style;
}

int getTitleLength() { return 0; }

string getTitlePosition(int index)
{
    return 0;
}

mapping getExitPosition()
{
    mapping exits = ([
        "north": "(1,1)",
        "east": "(1,1)",
        "south": "(1,1)",
        "west": "(1,1)",
    ]);
    return exits;
}

// �ئnbuild��A�Nbuild�]���㦳�����\��
int postCondition(object build)
{
    build->set("_IS_WELL_", 1);
}
