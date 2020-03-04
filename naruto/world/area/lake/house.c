#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�`�ޫ�");
    set("long","���W���F�@�Ӥw�g�G�k��֭n�걼����P�A�W���g�ۡu�`�ޫǡv
�i�J����u���|�P�d�l�W�񺡤F���y�A�Ф����j��l�W��F�@�ӥ���
���a�L�٦��@���p�����}�ѡA�ʭ��g�ۡy��x�z
");
    set("exits", ([
        "north" : ([ "filename": __DIR__"relice.c",
                      "x_axis": 12,
                      "y_axis": 13,
                 ]),
    ]));
    set("detail", ([
        "�`�ޫ�": "�@�ӻG�k���Y������P�C",
        "��x": "�W���g�F�ܦh�F��A�����G�u���᭱�����i�٫j�j����\Ū(read)�C",
    ]));
    set("objects", ([
    __DIR__"npc/zombie2.c" : 1,
    ]));
    setup();
}
void init()
{
    add_action("do_read", "read");
}
int do_read(string arg)
{
    string line;
    if( arg == "1" || arg == "�Ĥ@�i" || arg == "�@�i" ) {
        line  = "                     ��x�Ĥ��d���ʤC�Q�@�g\n";
        line += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        line += "�~���T�C�@�@�Ѯ�@��\n";
        line += "�@\n";
        line += "�i�J�o�Ӳ��髰���G�Q�~�A�کl�פ����D�ѥD�H���F�O�g�Q���A�٬O\n";
        line += "�ӳ��w�����é_�������j�����îa�C�n���O�ڦb�D�H�ܾK�s�ɤf�~�j\n";
        line += "�v���g�ӧڰ��ˤ��H�A�L�]���|��K�D���}�k�i���ڡI�o�K�D�����_\n";
        line += "���u�O���H�j�}���ɡA�H�K�@�ˮ��X�h�]���Ӧn�X�U�a�I�u���O��\n";
        line += "�����H���߰ʡA�n�O�گள�X�˥X�h��A�Z���O��½�F�I�o�˴N�i�H\n";
        line += "�\��C�ѧC�n�U���`�ި����F�I\n";
        line += "�@\n";
        line += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        write(line);
        return 1;
    }
    if( arg == "2" || arg == "�ĤG�i" || arg == "�G�i" ) {
        line  = "                     ��x�Ĥ��d���ʤC�Q�G�g\n";
        line += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        line += "�~���T�C�@�@�Ѯ�@��\n";
        line += "�@\n";
        line += "�گu�������F�I���ӥi�c���å�ڥ��N�S���L���˪�����I��ݤU��\n";
        line += "���F���|�N�O���|�I�ڥi�O�`�ޡI�`�ޭC�I�~�M�N�b���h���H�e����\n";
        line += "�F�ڤ@�Ӧե��A�o�˧ڦb��L���H�e�����٦����Y�s�b�H�̪�`�ݨ�\n";
        line += "�å�M�@�Ӥk�ĤH�ܿ˪�A�Ӥ��|�O�Q�Φo�Ө��N�ڲ{�b����m�a�I\n";
        line += "�o�i����I���٨S����K�D�����_���A���i�H�N�o�����}�O�I�ڥ�\n";
        line += "���Q�I��k���گ�o�쨺���_���~��I\n";
        line += "�@\n";
        line += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        write(line);
        return 1;
    }
    if( arg == "3" || arg == "�ĤT�i" || arg == "�T�i" ) {
        line  = "                     ��x�Ĥ��d���ʤC�Q�T�g\n";
        line += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        line += "�~���T�C�@�@�Ѯ�@��\n";
        line += "�@\n";
        line += "�o�ѧڤ@���N�ФF�ӵu���A�����Ȩ�����P���ǶħL�Z�h�̷��q�A�L\n";
        line += "��ť������K�M�w�����ڪ����ΡA���L�ڷ�M���|�۫H�L�̳o�ǶħL\n";
        line += "�A�ڨ��M�F�|�P�X�Ӥj���A�X�G�N�න���ħL�����ΤF�A�ϥ����ڮ�\n";
        line += "��F�����_���I�ڴN�A�]���ξ�߿������D�աI�����w�ƻݭn�@�Ѫ�\n";
        line += "�ɶ��A��O�ڨM�w���^�����~�򰵧ڳ̫�@�Ѫ��`�ޡA�@�Q���Ѥ�\n";
        line += "��ڴN�N�����t�@�Ӥg���A�N���Ī����򳣧ѤF�I\n";
        line += "�@\n";
        line += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        write(line);
        return 1;
    }
    if( arg == "4" || arg == "�ĥ|�i" || arg == "�|�i" ) {
        line  = "                     ��x�Ĥ��d���ʤC�Q�|�g\n";
        line += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        line += "�~���T�C�@�@�Ѯ�@��\n";
        line += "�@\n";
        line += "���ѧڤp���l�l���X�ۨ��å�M�k�Ĩp�|���ɭ����J�����Ǥ��A����\n";
        line += "�u���}�L�@�����g���٬O���ڦ��I�d���M���o�����������C���Ъ���\n";
        line += "�F�X������A�ڵo�{�o�����O���i��P�ɥ��}���A�C���@��}�ҫ�\n";
        line += "�t�@��K�|�d��A�߿W�_�ö��������O���ê��t�@�վ����A�b�}�ҫ�\n";
        line += "�ä��v�T��L�������B��C�b�h���������`���o�������@�I�I��\n";
        line += "�F�ѡA���O�ڪ��O�ʤS���O�ܦn�A�ҥH��o�g��x�g������A���ӷ|\n";
        line += "�s�]���u�X�@�i����}�ҩҦ��������H�ȡA�H����ɭԧڤS�ѤF�o�Q\n";
        line += "���������n���}�ҡI\n";
        line += "�@\n";
        line += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        write(line);
        return 1;
    }
    if( arg == "5" || arg == "�Ĥ��i" || arg == "���i" ) {
        line  = "                     ��x�Ĥ��d���ʤC�Q���g\n";
        line += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        line += "�~���T�C�@�@�Ѯ�@��\n";
        line += "�@\n";
        line += "�ħL�̦p�����ӤF�A�ڸ˰��S�Ư몺���b�`�ީФ��g�۳̫�@�g��x\n";
        line += "�A���W�o����N�O�ڪ��F��F�A�@�Q��u�O����........�~�����M��\n";
        line += "�ӤF���H���V���n�A�L�̤j�n�ټM�ۻ�����~���@���e����M�z���F\n";
        line += "�_�ӡA��Ӥ��w�g�T�i�����F�I�@ť���U�ڰ��W�Ĩ���f�A�~�o�{��\n";
        line += "�ӧکҧ䪺�ħL�A�����@�Ӥ��Ѫ��˦b�a�W�A�ӥ|�P�~�M�O�@�s....\n";
        line += "�ڤ��|�ݿ����I�֩w�O�@�s�Ԫ̡I�S�Q��کM�ħL�̪��͸ܳQ�L�̵�\n";
        line += "ť���F�I�ٱN�ħL�̱����Q�n�W�]�_�áI�i���o�{�o�@�����ڤw�g��\n";
        line += "��F�A�|�P���Q���A�S����k�k���C�ڥu�n�^����T�ν����`�ޫ�\n";
        line += "�~��N�o�������ӬO�r�ֵ�������x���ӵh�W�������C\n";
        line += "�H���N�����H���U�`�O�S�O�F���A�ڬ�M�Q��A�o�Ӳ��骺�Ƥ��]�I\n";
        line += "���ӴN���O�ܦn�A�{�b�o�˾�Ӥj�e������F�i�ӡA�[�W�������ӼW\n";
        line += "�[���ת��a�U�Q���Ű����_�ö��A�b�Y���i�������p�U�A�ڷQ��Ӳ�\n";
        line += "�����ӷ|�����򳴧a�I�S�Q���F�̫�~���D����`�ޤ]�O�ܩ��֪�\n";
        line += "��o�˪������u�O�n�Ӧh�F�C\n";
        line += "�@\n";
        line += "                                          �`��   �L�_ ��\n";
        line += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        write(line);
        return 1;
    }
    return notify_fail("�\Ū��x�Х�read <�s��>\n");
}
