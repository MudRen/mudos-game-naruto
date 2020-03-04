inherit ITEM;

mapping test = ([
    1: ([ "msg": "�U�C���@���O�����@����x���Ӱ����ơH\n"
                 "           (1) �O�@�H��\n"
                 "           (2) �e������\n"
                 "           (3) ���@�@��\n"
                 "           (4) ���ܰ]��\n",
          "correct": 4,
          "answer": 0,
       ]),
    2: ([ "msg": "�q�`�G�O�O�_������άO�H���򪫫~�H\n"
                 "           (1) �u�\\�лx���X�m\n"
                 "           (2) ���b�ݫe������\n"
                 "           (3) �a�b�Y�W���U�l\n"
                 "           (4) ��~�[\n",
          "correct": 1,
          "answer": 0,
       ]),
    3: ([ "msg": "���x�M�u�C�Z���v�����Y�O����H\n"
                 "           (1) �P���x�Ĺ諸��´\n"
                 "           (2) �Q���x���Ϊ��t������\n"
                 "           (3) �F���һ{�i������\n"
                 "           (4) ���x�C�ӳ̱j���N��\n",
          "correct": 3,
          "answer": 0,
       ]),
    4: ([ "msg": "�c�]�G��O����H\n"
                 "           (1) ����o�S���O�����~\n"
                 "           (2) �@�ثܱ`��������\n"
                 "           (3) �n�Y�����G\n"
                 "           (4) �Ѥj�p�Ұ��X�Ӫ��������a\n",
          "correct": 1,
          "answer": 0,
       ]),
    5: ([ "msg": "�c�]�G���O�̹J�줰��|�����L�O�H\n"
                 "           (1) �N���L\n"
                 "           (2) ��j\n"
                 "           (3) ���ӥ�\n"
                 "           (4) ����\n",
          "correct": 3,
          "answer": 0,
       ]),
    6: ([ "msg": "���x�����ӥs����W�r�H\n"
                 "           (1) �~��\n"
                 "           (2) �԰�\n"
                 "           (3) �K��\n"
                 "           (4) �ǧJ\n",
          "correct": 2,
          "answer": 0,
       ]),
    7: ([ "msg": "���x�O�p��P�_�������ӵ����h���a����H\n"
                 "           (1) �������h�ִN�h��\n"
                 "           (2) �̷ӯ�����~��\n"
                 "           (3) �Ѯ���ۤv�q\n"
                 "           (4) �̷Ө��@�ɬF�����¯٩�\n",
          "correct": 4,
          "answer": 0,
       ]),
    8: ([ "msg": "����󽦪G�ꪺ���������O�����H\n"
                 "           (1) �c�]�G�ꪺ�@��\n"
                 "           (2) �Y�F�|�ܦ��󽦤H\n"
                 "           (3) �G��O�ξ󽦰���\n"
                 "           (4) �Y�F�|�Q�j�����\n",
          "correct": 3,
          "answer": 0,
       ]),
    9: ([ "msg": "���x���O�]�O�O����˪����O�H\n"
                 "           (1) �ѤW�N�H�W�~�i�H�o��\n"
                 "           (2) �ѤQ���xĥ�M���W���N�@�P�o�ʧ���\n"
                 "           (3) ���������q�R���@�y�q��\n"
                 "           (4) �H�W�ҹ�\n",
          "correct": 4,
          "answer": 0,
       ]),
   10: ([ "msg": "�H�U��̤��O���x�N��H\n"
                 "           (1) ������\n"
                 "           (2) ���b\n"
                 "           (3) �ک_\n"
                 "           (4) �����S\n",
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
    set_name("���x�J������", ({ "navy entry-level test paper", "paper"}));
    set_weight(500);
    if( !clonep() ) {
        set("unit", "��");
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

string is_test_paper() { return "piece"; }
