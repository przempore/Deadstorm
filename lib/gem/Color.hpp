#ifndef GEM_COLOR_HPP
#define GEM_COLOR_HPP

#include <cstdint>

namespace Gem
{
    class Color
    {
    public:
        inline Color();
        inline Color(uint8_t r,
                     uint8_t g,
                     uint8_t b,
                     uint8_t a=255);

    public:
        static const Color s_aliceBlue;
        static const Color s_antiqueWhite;
        static const Color s_aqua;
        static const Color s_aquamarine;
        static const Color s_azure;
        static const Color s_beige;
        static const Color s_bisque;
        static const Color s_black;
        static const Color s_blanchedAlmond;
        static const Color s_blue;
        static const Color s_blueViolet;
        static const Color s_brown;
        static const Color s_burlyWood;
        static const Color s_cadetBlue;
        static const Color s_chartreuse;
        static const Color s_chocolate;
        static const Color s_coral;
        static const Color s_cornflowerBlue;
        static const Color s_cornsilk;
        static const Color s_crimson;
        static const Color s_cyan;
        static const Color s_darkBlue;
        static const Color s_darkCyan;
        static const Color s_darkGoldenrod;
        static const Color s_darkGray;
        static const Color s_darkGreen;
        static const Color s_darkKhaki;
        static const Color s_darkMagenta;
        static const Color s_darkOliveGreen;
        static const Color s_darkOrange;
        static const Color s_darkOrchid;
        static const Color s_darkRed;
        static const Color s_darkSalmon;
        static const Color s_darkSeaGreen;
        static const Color s_darkSlateBlue;
        static const Color s_darkSlateGray;
        static const Color s_darkTurquoise;
        static const Color s_darkViolet;
        static const Color s_deepPink;
        static const Color s_deepSkyBlue;
        static const Color s_dimGray;
        static const Color s_dodgerBlue;
        static const Color s_firebrick;
        static const Color s_floralWhite;
        static const Color s_forestGreen;
        static const Color s_fuchsia;
        static const Color s_gainsboro;
        static const Color s_ghostWhite;
        static const Color s_gold;
        static const Color s_goldenrod;
        static const Color s_gray;
        static const Color s_green;
        static const Color s_greenYellow;
        static const Color s_honeydew;
        static const Color s_hotPink;
        static const Color s_indianRed;
        static const Color s_indigo;
        static const Color s_ivory;
        static const Color s_khaki;
        static const Color s_lavender;
        static const Color s_lavenderBlush;
        static const Color s_lawnGreen;
        static const Color s_lemonChiffon;
        static const Color s_lightBlue;
        static const Color s_lightCoral;
        static const Color s_lightCyan;
        static const Color s_lightGoldenrodYellow;
        static const Color s_lightGray;
        static const Color s_lightGreen;
        static const Color s_lightPink;
        static const Color s_lightSalmon;
        static const Color s_lightSeaGreen;
        static const Color s_lightSkyBlue;
        static const Color s_lightSlateGray;
        static const Color s_lightSteelBlue;
        static const Color s_lightYellow;
        static const Color s_lime;
        static const Color s_limeGreen;
        static const Color s_linen;
        static const Color s_magenta;
        static const Color s_maroon;
        static const Color s_mediumAquamarine;
        static const Color s_mediumBlue;
        static const Color s_mediumOrchid;
        static const Color s_mediumPurple;
        static const Color s_mediumSeaGreen;
        static const Color s_mediumSlateBlue;
        static const Color s_mediumSpringGreen;
        static const Color s_mediumTurquoise;
        static const Color s_mediumVioletRed;
        static const Color s_midnightBlue;
        static const Color s_mintCream;
        static const Color s_mistyRose;
        static const Color s_moccasin;
        static const Color s_navajoWhite;
        static const Color s_oldLace;
        static const Color s_olive;
        static const Color s_oliveDrab;
        static const Color s_orange;
        static const Color s_orangeRed;
        static const Color s_orchid;
        static const Color s_paleGoldenrod;
        static const Color s_paleGreen;
        static const Color s_paleTurquoise;
        static const Color s_paleVioletRed;
        static const Color s_papayaWhip;
        static const Color s_peachPuff;
        static const Color s_peru;
        static const Color s_pink;
        static const Color s_plum;
        static const Color s_powderBlue;
        static const Color s_purple;
        static const Color s_red;
        static const Color s_rosyBrown;
        static const Color s_royalBlue;
        static const Color s_saddleBrown;
        static const Color s_salmon;
        static const Color s_sandyBrown;
        static const Color s_seaGreen;
        static const Color s_seaShell;
        static const Color s_sienna;
        static const Color s_silver;
        static const Color s_skyBlue;
        static const Color s_slateBlue;
        static const Color s_slateGray;
        static const Color s_snow;
        static const Color s_springGreen;
        static const Color s_steelBlue;
        static const Color s_tan;
        static const Color s_teal;
        static const Color s_thistle;
        static const Color s_tomato;
        static const Color s_transparentBlack;
        static const Color s_transparentWhite;
        static const Color s_turquoise;
        static const Color s_violet;
        static const Color s_wheat;
        static const Color s_white;
        static const Color s_whiteSmoke;
        static const Color s_yellow;
        static const Color s_yellowGreen;

    public:
        uint8_t m_r{0};
        uint8_t m_g{0};
        uint8_t m_b{0};
        uint8_t m_a{255};
    };
}

#include "gem/Color.inl"

#endif
