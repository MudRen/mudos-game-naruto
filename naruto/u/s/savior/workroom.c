#include <ansi.h>
#include <room.h>

inherit INN;

void create()
{
    set("short", "�ϰ�");
    set("long", "�N�檺�H���q�y�W�I�S�ӹL�A���H���T�ݰ_�}�}�HŸ�A�H�����٧��a��
�@�����ϫ˨����H�[�[���ਥ�y�C�o���s�j�����|�P�a�����w�A���W��
�_�F�@�D���X�A�@���p�ˬ�L���X��Ӭy�V�F��C�o�Ӫ��۵۬��R��������
����X��i�F�@�s�Ź����̤l�A�b�ϰ骺���ߦ��@���j��A��U��ۤ@�x�q
�l�^�A�����쪺�i�H�h�ոաC \n");
    set("exits", ([
        "wizard" : "/world/area/wizard/guildhall.c", 
    ]));
    setup();
    load_object("/daemon/board/savior");
}
