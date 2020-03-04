#include <ansi.h>
inherit ITEM;

int i=0;

void create()
{
    set_name("��߱o"NOR, ({ "polaroid", "pol" }));
    set("unit", "�x");
    set("value", 0);
    set("no_box", 1);
    set("long", "�ӹ������@�ءA����ߧY�N���᪺���e��{�X�ӡA�Q����K�C\n"
                "�ϥΤ�k��(use pol to <�Y�H>)\n");
    setup();
}

void do_use(object me, string arg)
{
    object obj, pic;

    if( !objectp(obj = present(arg, environment(me)))) {
        write("�S���o�ӤH...\n");
        return;
    }
    if( me->is_busy() ) {
        write("�A���b���A�S��k��ӡC\n");
        return;
    }
    if( me->is_fighting() ) {
        write("�԰��٤��ߩ�ӡH\n");
        return;
    }
    if( i >= 5 ) {
        write("�o�x�۾��w�g�S���n���F�C\n");
        return;
    }
    message_vision("\n$N���_��߱o���$n���D�G"HIG"�n��աI���@�ӡI\n\n"NOR, me, obj);

    pic = new(__DIR__"picture.c");

    if( !objectp(pic) ) {
        write("�o�x�����n���T�٤F...\n");
        destruct(pic);
        return;
    }
    message_vision(CYN"$n�ߧY�����\�F�Ӭ����� Pose�A�������I�Ӥ��X�l�աI\n\n\n"NOR, me, obj);

    pic->set("name", obj->query("name")+pic->query("name"));
    pic->set("id", obj->query("id")+" "+pic->query("id"));

    if( !obj->is_character() || obj->is_corpse() ) {
        pic->set("long", "�z�ǡI�A����F���ۤ��ԡI"+obj->query("name")+"�~�M�|�\ Pose�I�H\n");
        pic->set("pic", 0);
    } else if( obj->query("gender") == "female" && obj->query("race") == "human" ) {
        pic->set("long", obj->query("name")+"�b�Ӥ��W�ݰ_�ӤQ�����H�A�窺�D�`���\�I\n");
        pic->set("pic", 1);
    } else if( obj->query("gender") == "male" && obj->query("race") == "human" ) {
        pic->set("long", obj->query("name")+"�b�Ӥ��W�ݰ_�ӭ^�𤣤Z�A�窺�D�`���\�I\n");
        pic->set("pic", 2);
    } else {
        pic->set("long", obj->query("name")+"�b�Ӥ��W�ݰ_�Ӷ����ªZ�A�窺�D�`���\�I\n");
        pic->set("pic", 3);
    }
    if( !pic->move(me) ) {
        write("�A�����W�ӭ��F�A�S��k��a�s���ۤ��C\n");
        destruct(pic);
        return;
    }
    i++;
    return;
}
