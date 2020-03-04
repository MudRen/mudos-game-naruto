/*  edit.c

    Copyright (C) 1994-2000 Annihilator <annihilator@muds.net>

    This program is a part of ES2 mudlib. Permission is granted to use,
    modify, copy or distribute this program provided this copyright notice
    remains intact and subject to the restriction that this program MAY
    NOT be used in any way for monetary gain.

    Details of terms and conditions is available in the Copyright.ES2 file.
    If you don't receive this file along with this program, write to the
    primary author of ES2 mudlib: Annihilator <annihilator@muds.net>
*/

#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string file)
{
    SECURED_WIZARD_COMMAND;

    if( !file ) return notify_fail("���O�榡�Redit <�ɦW>\n");

    if( in_edit(me) ) return notify_fail("�A�w�g�b�ϥνs�边�F�C\n");

    seteuid(geteuid(this_player(1)));
    ed(resolve_path(me->query("cwd"), file));
    return 1;
}

int help(object me)
{
    write(@HELP
���O�榡 : edit <�ɦW>|edit here

�Q�Φ��@���O�i�����b�u�W�s���ɮסC

�b edit �U�`�Ϊ����O���[��:

�� �W�[(a), ���N(c) �Ұ� 'edit mode'.

�n���^ 'command mode', �h�b�@�檺�_�I��J '.' �A�� 'enter' ��.

$ - �o�ӲŸ��b command mode �û����N��̫�@�檺�渹.
:�Ʀr(n),(m)p ---- �C�X�ɮפ��e, n ���}�l�渹, m �������渹. �p�G�S��
                   m,n �h�C�X �{�b �Ҧb�檺���e. �p�G 'p' �e�u���@�ӼƦr
                   �h�C�X�Ʀr�ҫ��渹�����e.
:�Ʀr(n),(m)d ---- �R���� n �� m �檺���e. �p�G 'd' �e�u���@�ӼƦr, �h
                   �R���Ʀr�ҫ��渹�����e.
:�Ʀr(n)a     ---- �b n ���[�J�F��. ��O�i�J 'edit mode'
:�Ʀr(n)i     ---- �b n ��e�[�J�F��. ��O�i�J 'edit mode'
:�Ʀr(n)c     ---- �ק�� n �檺���e. ��O�i�J 'edit mode', ����
                   �A�ҥ��J���F�賣�|���N�� n ��즳�����e.
              [��: �o�ӫ��O�� �u���ġv�d��O�@��, �W�L�@��ä��|���A�ק�
                     n+1 �檺�F��.]
�p�G�S�����w�渹, �h�H�ثe�Ҧb�欰��.
:x            ---- �s�ɨ����} edit�C
:q            ---- ���} edit. [��: �����O�u�A�Ω���ɮפw�g�x�s�L��, �άO�ɮ�
                   �S���Q��ʹL.]
:Q            ---- �p�G�ɮ׳Q�ʹL, ���A���Q�g�J�Q��ʪ����e, �A�i�H�γo�ӫ�
                   �O���} edit.
:!<cmd>       ---- �b edit �U����Y�� mud ���O.
HELP
    );
    return 1;
}
