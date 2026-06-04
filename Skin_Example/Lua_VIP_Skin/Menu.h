#include "skin_data.h"
using on_change_callback = void (*)(int);
bool carspring;
std::string item_seprated_by_zero(std::vector<FSkinItem> skins)
{
  std::string out;
  for (int i = 0; i < skins.size(); i++)
  {
    std::string val = skins[i].name2;
    out += val;
    if (i < skins.size())
    {
      out += '\0';
    }
  }
  return out;
}
void RenderSkinItem(std::string label, CSkinsInfo &skins, on_change_callback cb = nullptr)
{
    std::string combo_label = "##" + label + "##combo";
    std::string input_label = "##" + label + "##intput";
    ImGui::Text(label.c_str());
    ImGui::SameLine();
    ImGui::SetNextItemWidth(100);
    if (ImGui::Combo(combo_label.c_str(), &skins.current_index, item_seprated_by_zero(skins.items).c_str()))
    {
        *skins.out = skins.Get();
    }
}
            RenderSkinItem("AKM", skindata.akm);
            RenderSkinItem("M416", skindata.m416);
            RenderSkinItem("SCAR-L", skindata.scarl);
            RenderSkinItem("AUG", skindata.aug);            
            RenderSkinItem("M762", skindata.m762);
            RenderSkinItem("GROZA", skindata.groza);
            RenderSkinItem("ACE32", skindata.ace32);
            RenderSkinItem("UMP45", skindata.ump45);
            RenderSkinItem("VECTOR", skindata.vector);
            RenderSkinItem("Tommy Gun", skindata.tommy);            
            RenderSkinItem("UZI", skindata.uzi);
            RenderSkinItem("KAR-98", skindata.kar98);
            RenderSkinItem("M24", skindata.m24);
            RenderSkinItem("AWM", skindata.awm);            
            RenderSkinItem("AMR", skindata.amr);
            RenderSkinItem("MK14", skindata.mk14);
            RenderSkinItem("MINI14", skindata.mini14);
            RenderSkinItem("M249", skindata.m249);
            RenderSkinItem("DP-28", skindata.dp28);
            RenderSkinItem("MG-3", skindata.mg3);
            RenderSkinItem("XM1014", skindata.xm1014);
            RenderSkinItem("S12K", skindata.s12k);
            RenderSkinItem("DBS", skindata.dbs);
            RenderSkinItem("PAN", skindata.pan);