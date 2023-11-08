#include <X11/X.h>
#include <X11/keysym.h>
#include <optional>
#include <unordered_map>

namespace ECS{
struct Keyboard_t{
  using UnorMapIt = std::unordered_map<KeySym, bool>::iterator;
  using UnorMapConstIt = std::unordered_map<KeySym, bool>::const_iterator;
  
  explicit Keyboard_t() = default;

  Keyboard_t(const Keyboard_t&)               = delete;
  Keyboard_t(Keyboard_t&&)                    = delete;
  Keyboard_t& operator=(const Keyboard_t&)    = delete;
  Keyboard_t& operator=(const Keyboard_t&&)   = delete;

  bool isKeyPressed(KeySym k) const noexcept;
  void keyPressed(KeySym k) noexcept;
  void keyReleased(KeySym k) noexcept;
    
private:
  const std::optional<UnorMapConstIt> getIterator(KeySym k) const noexcept;
        std::optional<UnorMapIt>      getIterator(KeySym k)       noexcept;

  std::unordered_map<KeySym, bool> m_pressedKeys{
         {   XK_BackSpace,              false }
        ,{   XK_Tab ,                   false }
        ,{   XK_Linefeed,               false }
        ,{   XK_Clear,                  false }
        ,{   XK_Return,                 false }
        ,{   XK_Pause,                  false }
        ,{   XK_Scroll_Lock,            false }
        ,{   XK_Sys_Req ,               false }
        ,{   XK_Escape          ,       false }        
        ,{   XK_Delete          ,       false }        
        ,{   XK_space           ,       false } 
        ,{   XK_exclam          ,       false }        
        ,{   XK_quotedbl        ,       false }
        ,{   XK_numbersign      ,       false }
        ,{   XK_dollar          ,       false }
        ,{   XK_percent         ,       false }
        ,{   XK_ampersand       ,       false }
        ,{   XK_apostrophe      ,       false }
        ,{   XK_quoteright      ,       false }
        ,{   XK_parenleft       ,       false }
        ,{   XK_parenright      ,       false }
        ,{   XK_asterisk        ,       false }
        ,{   XK_plus            ,       false }
        ,{   XK_comma           ,       false }
        ,{   XK_minus           ,       false }
        ,{   XK_period          ,       false }
        ,{   XK_slash           ,       false }
        ,{   XK_0               ,       false }
        ,{   XK_1               ,       false }
        ,{   XK_2               ,       false }
        ,{   XK_3               ,       false }
        ,{   XK_4               ,       false }
        ,{   XK_5               ,       false }
        ,{   XK_6               ,       false }
        ,{   XK_7               ,       false }
        ,{   XK_8               ,       false }
        ,{   XK_9               ,       false }
        ,{   XK_colon           ,       false }
        ,{   XK_semicolon       ,       false }
        ,{   XK_less            ,       false }
        ,{   XK_equal           ,       false }
        ,{   XK_greater         ,       false }
        ,{   XK_question        ,       false }
        ,{   XK_at              ,       false }
        ,{   XK_A               ,       false }
        ,{   XK_B               ,       false }
        ,{   XK_C               ,       false }
        ,{   XK_D               ,       false }
        ,{   XK_E               ,       false }
        ,{   XK_F               ,       false }
        ,{   XK_G               ,       false }
        ,{   XK_H               ,       false }
        ,{   XK_I               ,       false }
        ,{   XK_J               ,       false }
        ,{   XK_K               ,       false }
        ,{   XK_L               ,       false }
        ,{   XK_M               ,       false }
        ,{   XK_N               ,       false }
        ,{   XK_O               ,       false }
        ,{   XK_P               ,       false }
        ,{   XK_Q               ,       false }
        ,{   XK_R               ,       false }
        ,{   XK_S               ,       false }
        ,{   XK_T               ,       false }
        ,{   XK_U               ,       false }
        ,{   XK_V               ,       false }
        ,{   XK_W               ,       false }
        ,{   XK_X               ,       false }
        ,{   XK_Y               ,       false }
        ,{   XK_Z               ,       false }
        ,{   XK_bracketleft     ,       false }
        ,{   XK_backslash       ,       false }
        ,{   XK_bracketright    ,       false }
        ,{   XK_asciicircum     ,       false }
        ,{   XK_underscore      ,       false }
        ,{   XK_grave           ,       false }
        ,{   XK_quoteleft       ,       false }
        ,{   XK_a               ,       false }
        ,{   XK_b               ,       false }
        ,{   XK_c               ,       false }
        ,{   XK_d               ,       false }
        ,{   XK_e               ,       false }
        ,{   XK_f               ,       false }
        ,{   XK_g               ,       false }
        ,{   XK_h               ,       false }
        ,{   XK_i               ,       false }
        ,{   XK_j               ,       false }
        ,{   XK_k               ,       false }
        ,{   XK_l               ,       false }
        ,{   XK_m               ,       false }
        ,{   XK_n               ,       false }
        ,{   XK_o               ,       false }
        ,{   XK_p               ,       false }
        ,{   XK_q               ,       false }
        ,{   XK_r               ,       false }
        ,{   XK_s               ,       false }
        ,{   XK_t               ,       false }
        ,{   XK_u               ,       false }
        ,{   XK_v               ,       false }
        ,{   XK_w               ,       false }
        ,{   XK_x               ,       false }
        ,{   XK_y               ,       false }
        ,{   XK_z               ,       false }
        ,{   XK_braceleft       ,       false }
        ,{   XK_bar             ,       false }
        ,{   XK_braceright      ,       false }
        ,{   XK_asciitilde      ,       false }
        ,{   XK_nobreakspace    ,       false }
        ,{   XK_exclamdown      ,       false }
        ,{   XK_cent            ,       false }
        ,{   XK_sterling        ,       false }
        ,{   XK_currency        ,       false }
        ,{   XK_yen             ,       false }
        ,{   XK_brokenbar       ,       false }
        ,{   XK_section         ,       false }
        ,{   XK_diaeresis       ,       false }
        ,{   XK_copyright       ,       false }
        ,{   XK_ordfeminine     ,       false }
        ,{   XK_guillemotleft   ,       false }
        ,{   XK_notsign         ,       false }
        ,{   XK_hyphen          ,       false }
        ,{   XK_registered      ,       false }
        ,{   XK_macron          ,       false }
        ,{   XK_degree          ,       false }
        ,{   XK_plusminus       ,       false }
        ,{   XK_twosuperior     ,       false }
        ,{   XK_threesuperior   ,       false }
        ,{   XK_acute           ,       false }
        ,{   XK_mu              ,       false }
        ,{   XK_paragraph       ,       false }
        ,{   XK_periodcentered  ,       false }
        ,{   XK_cedilla         ,       false }
        ,{   XK_onesuperior     ,       false }
        ,{   XK_masculine       ,       false }
        ,{   XK_guillemotright  ,       false }
        ,{   XK_onequarter      ,       false }
        ,{   XK_onehalf         ,       false }
        ,{   XK_threequarters   ,       false }
        ,{   XK_questiondown    ,       false }
        ,{   XK_Agrave          ,       false }
        ,{   XK_Aacute          ,       false }
        ,{   XK_Acircumflex     ,       false }
        ,{   XK_Atilde          ,       false }
        ,{   XK_Adiaeresis      ,       false }
        ,{   XK_Aring           ,       false }
        ,{   XK_AE              ,       false }
        ,{   XK_Ccedilla        ,       false }
        ,{   XK_Egrave          ,       false }
        ,{   XK_Eacute          ,       false }
        ,{   XK_Ecircumflex     ,       false }
        ,{   XK_Ediaeresis      ,       false }
        ,{   XK_Igrave          ,       false }
        ,{   XK_Iacute          ,       false }
        ,{   XK_Icircumflex     ,       false }
        ,{   XK_Idiaeresis      ,       false }
        ,{   XK_ETH             ,       false }
        ,{   XK_Eth             ,       false }
        ,{   XK_Ntilde          ,       false }
        ,{   XK_Ograve          ,       false }
        ,{   XK_Oacute          ,       false }
        ,{   XK_Ocircumflex     ,       false }
        ,{   XK_Otilde          ,       false }
        ,{   XK_Odiaeresis      ,       false }
        ,{   XK_multiply        ,       false }
        ,{   XK_Oslash          ,       false }
        ,{   XK_Ooblique        ,       false }
        ,{   XK_Ugrave          ,       false }
        ,{   XK_Uacute          ,       false }
        ,{   XK_Ucircumflex     ,       false }
        ,{   XK_Udiaeresis      ,       false }
        ,{   XK_Yacute          ,       false }
        ,{   XK_THORN           ,       false }
        ,{   XK_Thorn           ,       false }
        ,{   XK_ssharp          ,       false }
        ,{   XK_agrave          ,       false }
        ,{   XK_aacute          ,       false }
        ,{   XK_acircumflex     ,       false }
        ,{   XK_atilde          ,       false }
        ,{   XK_adiaeresis      ,       false }
        ,{   XK_aring           ,       false }
        ,{   XK_ae              ,       false }
        ,{   XK_ccedilla        ,       false }
        ,{   XK_egrave          ,       false }
        ,{   XK_eacute          ,       false }
        ,{   XK_ecircumflex     ,       false }
        ,{   XK_ediaeresis      ,       false }
        ,{   XK_igrave          ,       false }
        ,{   XK_iacute          ,       false }
        ,{   XK_icircumflex     ,       false }
        ,{   XK_idiaeresis      ,       false }
        ,{   XK_eth             ,       false }
        ,{   XK_ntilde          ,       false }
        ,{   XK_ograve          ,       false }
        ,{   XK_oacute          ,       false }
        ,{   XK_ocircumflex     ,       false }
        ,{   XK_otilde          ,       false }
        ,{   XK_odiaeresis      ,       false }
        ,{   XK_division        ,       false }
        ,{   XK_oslash          ,       false }
        ,{   XK_ooblique        ,       false }
        ,{   XK_ugrave          ,       false }
        ,{   XK_uacute          ,       false }
        ,{   XK_ucircumflex     ,       false }
        ,{   XK_udiaeresis      ,       false }
        ,{   XK_yacute          ,       false }
        ,{   XK_ydiaeresis      ,       false }
        ,{   XK_thorn           ,       false }
  };
};
}
