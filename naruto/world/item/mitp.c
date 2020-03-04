/* testpaper.c �U�ԦҸը� write by -Acme- */

inherit ITEM;

mapping test = ([
    1: ([ "msg": "�b���v�Ԫ̥@�ɤ��A�̤j���Ԫ̧��O�H\n"
                 "           (1) ������\n"
                 "           (2) ������\n"
                 "           (3) �츭��\n"
                 "           (4) ������\n",
          "correct": 3,
          "answer": 0,
       ]),
    2: ([ "msg": "�Ԫ̧����q�`�|�]�߷t����´�A�q�`�O�ΨӡH\n"
                 "           (1) �d����\n"
                 "           (2) �q�ƶ��СB�t���B�l���q��\n"
                 "           (3) �ԳN���ɲ�´\n"
                 "           (4) �O�@����\n",
          "correct": 2,
          "answer": 0,
       ]),
    3: ([ "msg": "�Ԯѡu�{�L���̬Ұ}�C�b�e�v �� \"�b\" �Ӧp�������ӨϥΩG�L�H\n"
                 "           (1) �����X�X���} �������P�����򦨶��\n"
                 "           (2) ���� ���� ���\n"
                 "           (3) ���� ��� �p���\n"
                 "           (4) �k�� ���� ���� ������\n",
          "correct": 1,
          "answer": 0,
       ]),
    4: ([ "msg": "����O�d�J�ԡH\n"
                 "           (1) �O�@�ح���\n"
                 "           (2) �ϥΧԳN�B�۳N����q��\n"
                 "           (3) ���������\n"
                 "           (4) �O�@�ز�´\n",
          "correct": 2,
          "answer": 0,
       ]),
    5: ([ "msg": "�ϥΪk�N�e�����z�L����ʧ@�ӵo�ʡH\n"
                 "           (1) ���x����\n"
                 "           (2) �˥�\n"
                 "           (3) �����\n"
                 "           (4) �s�򪺤�L\n",
          "correct": 4,
          "answer": 0,
       ]),
    6: ([ "msg": "�츭���Ĥ��N���v�O�H\n"
                 "           (1) �᭸\n"
                 "           (2) �ۨӤ]\n"
                 "           (3) ����\n"
                 "           (4) ��H\n",
          "correct": 3,
          "answer": 0,
       ]),
    7: ([ "msg": "�U�C���@��O�츭�����q�ԡH\n"
                 "           (1) ��l�Y\n"
                 "           (2) �j�D�Y\n"
                 "           (3) �p�D�Y\n"
                 "           (4) �L³�Y\n",
          "correct": 2,
          "answer": 0,
       ]),
    8: ([ "msg": "����O��N�H\n"
                 "           (1) �Q���餺���d�J�Ԧb�ۤw�ι�⨭�W�ϥΪ��k�N\n"
                 "           (2) �O�@����ޡA�԰��e�ϥΪ��x����\n"
                 "           (3) �H��ı�s�y�ʯv���A\n"
                 "           (4) �Q�Φۤw�����鰵�X����\n",
          "correct": 4,
          "answer": 0,
       ]),
    9: ([ "msg": "����O�ԳN�H\n"
                 "           (1) �Q���餺���d�J�Ԧb�ۤw�ι�⨭�W�ϥΪ��k�N\n"
                 "           (2) �O�@����ޡA�԰��e�ϥΪ��x����\n"
                 "           (3) �H��ı�s�y�ʯv���A\n"
                 "           (4) �Q�Φۤw�����鰵�X����\n",
          "correct": 1,
          "answer": 0,
       ]),
   10: ([ "msg": "����O�۳N�H\n"
                 "           (1) �Q���餺���d�J�Ԧb�ۤw�ι�⨭�W�ϥΪ��k�N\n"
                 "           (2) �O�@����ޡA�԰��e�ϥΪ��x����\n"
                 "           (3) �H��ı�s�y�ʯv���A\n"
                 "           (4) �Q�Φۤw�����鰵�X����\n",
          "correct": 3,
          "answer": 0,
       ]),
]);

string do_look_long()
{
    int index, size;
    string msg;
    
    size = sizeof(test);

    msg  = this_object()->query("name") + ", �Шϥ� answer ���O�@���C\n";
    msg += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";

    for(index=1;index<=size;index++) {
        if( undefinedp(test[index]) ) continue;
        msg += sprintf("�]%|3s�^%2d. %s\n",
               test[index]["answer"] ? test[index]["answer"] + "" : "",
               index,
               test[index]["msg"] );
    }

    msg += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w";
    return msg;
}

int do_check()
{
    int index, score = 0 , size;
    size = sizeof(test);

    for(index=1;index<=size;index++) {
        if( undefinedp(test[index]) ) continue;
        if( test[index]["correct"] == test[index]["answer"] ) score += 10;   //����@�D�o�Q��
    }

    return score;
}

void create()
{
    set_name("�츭���U�ԦҸը�", ({ "muye inferior ninja test paper", "paper"}));
    set_weight(500);
    if( !clonep() ) {
        set("unit", "�i");
        set("value", 0);
        set("no_box", 1);
        set("long", (: do_look_long :) );
    }
    setup();
}

void init()
{
    add_action("do_answer", "answer");
}

int do_answer(string arg)
{
    int no, ans;

    // paper���O�buser���W���|��answer�ʧ@
    if( !userp(environment(this_object())) ) return 0;

    if( !arg ) return notify_fail("���O�榡�G answer <�D��> <����>\n");

    if( sscanf(arg, "%d %d", no, ans) != 2 ) return notify_fail("���O�榡�G answer <�D��> <����>\n");

    if( undefinedp(test[no]) ) return notify_fail("�S���o�@���D�ءC\n");
    
    tell_object(this_player(), "�A�b�� " + no + " �D��������g�W " + ans + " �o�ӵ��סC\n");

    test[no]["answer"] = ans;

    this_object()->set("long", do_look_long());

    return 1;
}

string is_test_paper() { return "muye"; }
