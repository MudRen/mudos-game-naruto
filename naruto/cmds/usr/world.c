#include <command.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    write(NOR"
_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

       ����h�A                  "BBLU+HIW"������"NOR"
          ��                      ��
        "BGRN"�ԨƪL"NOR"�w�e���Գ��w�����K�D                  "HIB"���I"NOR"
                 ��           ��                     ��
   �H���ӪL �D�H���q       �����ۥ�     �@�U���D  �����}�]     �m���A��
�@      �@    ��      �@�@�@�@���@             �@    �@�@         ��
  �@�@�@�@�^���}�� �@�@���v�p�|        ���Z��w"BBLU+HIW"�츭��"NOR"  ������  �~����w"BYEL+HIW"�ѤW�H��"NOR"
        ��               ��    �@          ��       �@   ��  ��
�H�������w"BGRN"�g���˪L"NOR"  ���v�_�ޢw��{��w"BGRN+HIW"���`�˪L"NOR"     "BGRN"�~�����L"NOR"
    �U�@     �U   ��   ��        ��      �@���@�@    �@ ��
 �F�y�p���w"BBLU+HIW"�H���q"NOR"�@�@"BGRN"��Q�L"NOR"�@ "BYEL+BLU"�a�U�F��"NOR"  "BGRN+HIW"���`�M��"NOR"   �@�~�����w"BGRN"�j�Ѵ˪L"NOR"
                      ��         ��                ��
        "BGRN+HIW"�շҬ}�]"NOR"�w�\\�H����    "HIK"�H����"NOR"           "BGRN+HIK"�w��L"NOR"�w"BRED+HIK"�§|�ڱ_��"NOR"
                    ��        ��               ��
                 "HIB"�F���r"NOR"  "BRED+HIK"�O�Ҥs��"NOR"�w"BGRN+HIK"�߻G�L"NOR"�w"HIK"���z�s��"NOR"�w"BRED+HIK"���]�l��"NOR"�w"BRED+HIK"�j�J�}"NOR"
                            ��                          ��
              "BYEL+HIK"�_���F�z"NOR"    "HIK"�����"NOR"�w"HIK"�]�T�s��"NOR"         "BRED+HIK"���㲴�ڳ��S"NOR"
                 ��         ��        ��    
              "HIK"�h�C��a"NOR"�w"HIK"�L�ɪ����"NOR" "HIK"�L�����"NOR"�w"BGRN+HIK"�j��L"NOR"�w"BGRN+HIK"�p��L"NOR"       "HIK"�`���_�V"NOR"
                 ��                   ��       ��      ��            ��    
   "BRED+HIK"�s��"NOR"       "BYEL+HIK"�n���F�z"NOR"              "HIK"�c����"NOR"   "BGRN+HIK"�¤�L"NOR"�w"BGRN+HIK"�դ�L"NOR"        "HIK"���P�p"NOR"
    ��         ��                          ��          ��          ��   
 "BYEL+HIK"�n���F�z"NOR"�w"HIK"�F����"NOR"                      "HIK"�Z������"NOR"     "BGRN+HIK"�A���O�L"NOR"�w"HIK"���ߦa"NOR"

                                                "HIK"�j�N���"NOR"
                                                   ��
    "BBLU+HIW"�q�k�q"NOR"   "BGRN+HIW"���s�C�q"NOR"                          "HIK"���Z�H�q��"NOR"    "HIK"���H���q"NOR"
      ��        ��                                 ��           ��
"BBLU"����������������������������������������"NOR"
"BBLU"�������������������㰶�j����D�������������������"NOR"
"BBLU"����������������������������������������"NOR"
        ��                                                 ��
      "BGRN+HIW"�p��q"NOR"                                            "HIK"������"NOR"�w"HIK"������"NOR"
                                                           ��       �@
                                                        "BGRN+HIK"�����˪L"NOR"  "HIK"�����r�h"NOR"
                                                            �@ 
                                                           "HIK"��v�s"NOR"


                                   "HIK"���褧��"NOR"

_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

"NOR);
    return 1;
}

int help()
{
    write(@TEXT
���O�榡�Gworld

�A�i�H�ϥγo�ӫ��O�d�ݥثe�Ҧ��ϰ�
�H�U�C��Ϥ��U�ϰ춡���ݩʡG

�¦�G���}��ϰ�
�Ǧ�G�@��ϰ�
�Ŧ�G���צM�I�ϰ�
����G���צM�I�ϰ�
�ũ��G���v�ϰ�
�񩳡G�˪L�ϰ�
�����G�F�z�ϰ�
�����G�M�I�w�w��
�ũ��զr�G�����ϰ�(�q�`��save�I)
�����զr�G�ѤW�H���M��
�񩳥զr�G�շҥΰϰ�
�����զr�G���צM�I�ϰ�

TEXT
    );
    return 1;
}
