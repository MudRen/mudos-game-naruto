// write by -Acme-

#include <npc.h>

inherit F_VILLAGER;
inherit F_TRAINER;    // �V�m�Ԫ�

/* guild: muye   �츭�Ԫ̧�
          yinyin �����Ԫ̧�
          wuyin  �����Ԫ̧�
          shayin �����Ԫ̧�
          yuyin  �B���Ԫ̧�
          yunyin �����Ԫ̧�
          caoyin �����Ԫ̧�
          puyin  �r���Ԫ̧�
*/

void create()
{
    set_name("���ߪ�", ({ "sin sin zhang master", "master" }) );
    set_race("human");
    set_level(40);
    set_class("superior");    //�W��
    set("age", 35);
    set("title", "�s��ɮv");
    set("long", "�L�O�@��s��ǰ|�̱M�u���Юv�A�оɷs��@�ǰ򥻧ޯ�A�A�i�H�Q\n"
                "�� train ���O�Ӿǲߤ@�ǰ򥻪��ޯ�C\n"
                "�� list ���O�d�ߥi�H�ǲߪ��ޯ�C��C\n");

    // �]�w�Ԫ̧��A�ۦP���Ԫ̧��~�|��, �]�w all �����Ԫ̧�
    set("guild", "all");

    // �]�w��V�m���ޯ�
    //
    // set_train(�ޯ�W, �O�_�i�����߱o, �ǲ߸ӧޯ�һݭn�����ⵥ��, ���ޯ�i�ǲߨ쪺�W������)
    //
    // ���a�S���ӧޯ�ɡA�Y"�O�_�i�����߱o"�o�ӳ]�w�Ȭ��D�s�ȮɡA���a�V�V�m�̾ǲ߮ɫh�i�O��
    // �o�ӧޯ��lv1�A�Ӧ�lv���ޯ�~�i�H���I�~����m�C�G�i�Ω�S��ޡA�n�����o��lv���i�V�m�C
    //
    set_train("combat", 1, 1, 100);               // �氫�ޥ�             F��
    set_train("dodge", 1, 1, 100);                // �{���ޥ�             F��
    set_train("parry", 1, 1, 100);                // �׮�ޥ�             F��
    set_train("heavy hit", 1, 5, 100);            // �������N             F��
    set_train("savage hit", 1, 5, 100);           // �������N             F��
    set_train("continual hit", 1, 5, 100);        // �s�����N             F��
/*
    set_train("force", 1, 10, 100);               // ��N                 F��
    set_train("ninja", 1, 10, 100);               // �ԳN                 F��
    set_train("magic", 1, 10, 100);               // �۳N                 F��
*/
/*
    set_train("alter ego", 0, 20, 100);           // �ԳN�G�����N         
    set_train("substitute", 0, 15, 100);          // �ԳN�G�����N         
    set_train("shadow", 0, 50, 100);              // �ԳN�G�v�����N       
    set_train("thunder cut", 0, 60, 100);         // �ԳN�G�p��           S��
    set_train("reincarnation", 0, 80, 100);       // �ԳN�G©�g���       S��
    set_train("moon dance", 0, 55, 100);          // �ԳN�G�s��R         A��
    set_train("wind blade", 0, 60, 100);          // �ԳN�G���b           A��
    set_train("snake kill", 0, 65, 100);          // �ԳN�G���D�۱��N     A��
    set_train("water-water fall", 0, 50, 100);    // �ԳN�G���P�E�j�r���N A��
    set_train("water-water dragon", 0, 40, 100);  // �ԳN�G���P�E���s�u�N B��
    set_train("plover", 0, 55, 100);              // �ԳN�G�d��           A��
    set_train("soul dies", 0, 45, 100);           // �ԳN�G����N         B��
    set_train("puppet", 0, 35, 100);              // �ԳN�G���w�N         C��
    set_train("whirlwind", 0, 30, 100);           // �ԳN�G�ۭ��N         C��
    set_train("fire-dragon fire", 0, 30, 100);    // �ԳN�G���P�E�s���N   C��
    set_train("fire-bold fireball", 0, 25, 100);  // �ԳN�G���P�E�����y�N C��
    set_train("fire-phoenix fire", 0, 20, 100);   // �ԳN�G���P�E��P���N C��
    set_train("animal taming", 0, 10, 100);       // �ԳN�G���~�N         E��
    set_train("bad worm", 0, 40, 100);            // �ԳN�G�H�a�γN       -��
    set_train("sand burial", 0, 40, 100);         // �ԳN�G���r�e��       -��
    set_train("sand tie", 0, 30, 100);            // �ԳN�G�⿣�^         -��
    set_train("sand armor", 0, 50, 100);          // �ԳN�G�ⲯ��         -��
    set_train("sand shield", 0, 60, 100);         // �ԳN�G���           -��

    set_train("inside lotus", 0, 60, 100);        // ��N�G�ؽ���         A��
    set_train("outside lotus", 0, 50, 100);       // ��N�G����         B��
    set_train("shadow leaf", 0, 30, 100);         // ��N�G�v�R��         C��
    set_train("lion attack", 0, 30, 100);         // ��N�G��l�s�u       C��
    set_train("muscle tank", 0, 25, 100);         // ��N�G�׼u�Ԩ�       C��
    set_train("thousand year kill", 0, 20, 100);  // ��N�G�d�~��         E��
    set_train("double physique", 0, 30, 100);     // ��N�G���ƳN         -
    set_train("sixty palms", 0, 50, 100);         // ��N�G�K�����Q�|�x   -
    set_train("sky palm", 0, 40, 100);            // ��N�G�K���x�^��     -

    set_train("five elements seal", 0, 70, 100);  // �ʦL�G����ʦL�N     A��
    set_train("five elements unseal", 0, 70, 100);// �ʦL�G����ѦL�N     A��
*/
    setup();

    // �H���������ޯ�]�w
    set_skill("dodge", 200);               // �򥻡G �j�קޥ�
    set_skill("parry", 200);               // �򥻡G ���m�ޥ�
    set_skill("combat", 200);              // �򥻡G �氫�ޥ�
    set_skill("savage hit", 200);          // �򥻡G ����
    set_skill("heavy hit", 200);           // �򥻡G ����
    set_skill("continual hit", 200);       // �򥻡G �s��
    set_skill("force", 180);               // �򥻡G ��N
    set_skill("ninja", 200);               // �򥻡G �ԳN
    set_skill("substitute", 180);          // �ԳN�G �����N

    map_skill("dodge", "substitute");      // �ϥΧޯ�u�����N�v��j�קޥ��W
}
