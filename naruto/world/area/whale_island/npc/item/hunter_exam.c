/* testpaper.c �U�ԦҸը� write by -Acme- */

inherit ITEM;

mapping test = ([
    1: ([ "msg": "���o�y�H���Ӧ�����n�B�H\n"
                 "           (1) �i�H�i�J�T��i�J����a\n"
                 "           (2) �ܽ���ӥi�H�C���l�Y�藍��\n"
                 "           (3) �W���d�ߤ��@�]�I\n"
                 "           (4)  �H�W�ҬO\n",
          "correct": 4,
          "answer": 0,
       ]),
    2: ([ "msg": "�U�����Ӥ��O�X�k���y�H���šH\n"
                 "           (1) �G�P�y�H\n"
                 "           (2) �@�V�y�H\n"
                 "           (3) �L���y�H\n"
                 "           (4) �����y�H\n",
          "correct": 2,
          "answer": 0,
       ]),
    3: ([ "msg": "�p�n�ײߩ���O�A�����������}�餺�𪺳q�D�A�U�z�������O�i�઺���}�覡�H\n"
                   "           (1) �߷Q���覡�ӥ��}���\n"
                 "           (2) �O�H�Ω��O�j��}�z�����\n"
                 "           (3) �C�ѹ�۶g�D���H�H�H���A�O�̧���o����O����k\n"
                 "           (4) �ѥ��L�H�A�Y�@�Ѧ��W���ө��M�N�⮩�F�A�@�d�U�H���u�|���@��\n",
          "correct": 3,
          "answer": 0,
       ]),
    4: ([ "msg": "����O����O�H\n"
                 "           (1) �ήe�@�ӤH�ܷ|�G�o\n"
                 "           (2) �ϥίS����ު���q��\n"
                 "           (3) �f�������\n"
                 "           (4) �O�@�ز�´\n",
          "correct": 2,
          "answer": 0,
       ]),
    5: ([ "msg": "�U�z����O���|�j��A��̴y�z����H\n"
                 "           (1) ��G��q�餺��լy�X���ͩR��q(��)�A�d�b����|�P\n"
                 "           (2) ���G�����餺����� �A�Ϩ���O���S���𴲵o�X�Ӫ����A\n"
                 "           (3) �m�G�X�i�餺��� �A�o���X�񥭱`��j�q���� \n"
                 "           (4) �o�G�N��Y�����᪺���o�X�H�����ĤH\n",
          "correct": 4,
          "answer": 0,
       ]),
    6: ([ "msg": "�U�z����O�����ΧޡA��̴y�z����H\n"
                 "           (1) �P�G �N��]��⤤�Ҵ�����A�Ǧ���Ӫ���i��j�ơA�O�����ΧޡC\n"
                 "           (2) ��G�H���鬰���ߡA�ϥΡy�m�z�N�y��z���d���X�j\n"
                 "           (3) ��G�Τ񥭱`��h����n����ӼW�j�𨾤O\n"
                 "           (4) ���G�H�m�N��������A�u�ධ������U�b����\n",
          "correct": 4,
          "answer": 0,
       ]),
    7: ([ "msg": "�U�������ײߩ���O���y�z��̤����T�H\n"
                 "           (1) �C�ӤH�̥L�����ʡA�A�X���P���誺����O\n"
                 "           (2) ����O�M�C�ӤH���өʦ����C�Y�M�ۤv���S�ʤ��X�A�Q�ǧO������O�O�@��ܨ��W����\n"
                 "           (3) ��{�ƨt�M�ާ@�t������O�̫�Ӧ����|���ܬ��S��t\n"
                   "           (4) �C���y�H���¥����׻����ө��t��O���ؼЫe�i\n",
          "correct": 4,
          "answer": 0,
       ]),
    8: ([ "msg": "�U���y�z�ϥΤ��������ˬd���j�t�������A��̤��i��o�͡H\n"
                 "           (1) �j�ƨt�G���q����\n"
                 "           (2) �S��t�G���ܦ�������\n"
                 "           (3) ��X�t�G�����C�����\n"
                 "           (4) �ާ@�t�G�𸭲���\n"
                 "           (5) ��{�ƨt�G�����X�{����\n"
                 "           (6) �ܤƨt�G�������D����\n",
          "correct": 2,
          "answer": 0,
       ]),
    9: ([ "msg": "�U����������O�P�ӤH�����ʴy�z�A��̤����T�H\n"
                 "           (1) �j�ƨt�G�Y��²��\n"
                 "           (2) �ܤƨt�G���еL�`�B�R�F�H\n"
                 "           (3) ��X�t�G���w���_�ۤw������Y�A�n�����j��\n"
                 "           (4) �ާ@�t�G�R���D�z�B�ڦ�گ�\n",
          "correct": 3,
          "answer": 0,
       ]),
   10: ([ "msg": "�����ۼv�ȹΪ����СA�U����̤����T�H\n"
                 "           (1) �ۼv�ȹγ��OA�Ū��q�r��\n"
                 "           (2) �έ��@���G�ʸU�H\n"
                 "           (3) ���W����12�}�j�諸��C\n"
                 "           (4) ��C�W���ӹέ������X\n",
          "correct": 2,
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
    set_name("�y�H��������", ({ "hunter inital test paper", "paper"}));
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

string is_test_paper() { return "hunter"; }

