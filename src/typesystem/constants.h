#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Plotypus
{
    // ====================================================================== //
    // symbol contants
    // source: https://ayapin-film.sakura.ne.jp/Gnuplot/Docs/ps_guide.pdf

    constexpr auto SYMBOL_ALPHA                 = "{/symbol a}";
    constexpr auto SYMBOL_BETA                  = "{/symbol b}";
    constexpr auto SYMBOL_CHI                   = "{/symbol c}";
    constexpr auto SYMBOL_DELTA                 = "{/symbol d}";
    constexpr auto SYMBOL_EPSILON               = "{/symbol e}";
    constexpr auto SYMBOL_PHI                   = "{/symbol f}";
    constexpr auto SYMBOL_GAMMA                 = "{/symbol g}";
    constexpr auto SYMBOL_ETA                   = "{/symbol h}";
    constexpr auto SYMBOL_ITOA                  = "{/symbol i}";
    constexpr auto SYMBOL_VARPHI                = "{/symbol j}";
    constexpr auto SYMBOL_KAPPA                 = "{/symbol k}";
    constexpr auto SYMBOL_LAMBDA                = "{/symbol l}";
    constexpr auto SYMBOL_MU                    = "{/symbol m}";
    constexpr auto SYMBOL_NU                    = "{/symbol n}";
    constexpr auto SYMBOL_OMICRON               = "{/symbol o}";
    constexpr auto SYMBOL_PI                    = "{/symbol p}";
    constexpr auto SYMBOL_THETA                 = "{/symbol q}";
    constexpr auto SYMBOL_RHO                   = "{/symbol r}";
    constexpr auto SYMBOL_SIGMA                 = "{/symbol s}";
    constexpr auto SYMBOL_TAU                   = "{/symbol t}";
    constexpr auto SYMBOL_UPSILON               = "{/symbol u}";
    constexpr auto SYMBOL_VARPI                 = "{/symbol v}";
    constexpr auto SYMBOL_OMEGA                 = "{/symbol w}";
    constexpr auto SYMBOL_XI                    = "{/symbol x}";
    constexpr auto SYMBOL_PSI                   = "{/symbol y}";
    constexpr auto SYMBOL_ZETA                  = "{/symbol z}";

    constexpr auto SYMBOL_CAPITAL_ALPHA         = "{/symbol A}";
    constexpr auto SYMBOL_CAPITAL_BETA          = "{/symbol B}";
    constexpr auto SYMBOL_CAPITAL_CHI           = "{/symbol C}";
    constexpr auto SYMBOL_CAPITAL_DELTA         = "{/symbol D}";
    constexpr auto SYMBOL_CAPITAL_EPSILON       = "{/symbol E}";
    constexpr auto SYMBOL_CAPITAL_PHI           = "{/symbol F}";
    constexpr auto SYMBOL_CAPITAL_GAMMA         = "{/symbol G}";
    constexpr auto SYMBOL_CAPITAL_ETA           = "{/symbol H}";
    constexpr auto SYMBOL_CAPITAL_ITOA          = "{/symbol I}";
    constexpr auto SYMBOL_CAPITAL_VARPHI        = "{/symbol J}";
    constexpr auto SYMBOL_CAPITAL_KAPPA         = "{/symbol K}";
    constexpr auto SYMBOL_CAPITAL_LAMBDA        = "{/symbol L}";
    constexpr auto SYMBOL_CAPITAL_MU            = "{/symbol M}";
    constexpr auto SYMBOL_CAPITAL_NU            = "{/symbol N}";
    constexpr auto SYMBOL_CAPITAL_OMICRON       = "{/symbol O}";
    constexpr auto SYMBOL_CAPITAL_PI            = "{/symbol P}";
    constexpr auto SYMBOL_CAPITAL_THETA         = "{/symbol Q}";
    constexpr auto SYMBOL_CAPITAL_RHO           = "{/symbol R}";
    constexpr auto SYMBOL_CAPITAL_SIGMA         = "{/symbol S}";
    constexpr auto SYMBOL_CAPITAL_TAU           = "{/symbol T}";
    constexpr auto SYMBOL_CAPITAL_UPSILON       = "{/symbol U}";
    constexpr auto SYMBOL_CAPITAL_VARPI         = "{/symbol V}";
    constexpr auto SYMBOL_CAPITAL_OMEGA         = "{/symbol W}";
    constexpr auto SYMBOL_CAPITAL_XI            = "{/symbol X}";
    constexpr auto SYMBOL_CAPITAL_PSI           = "{/symbol Y}";
    constexpr auto SYMBOL_CAPITAL_ZETA          = "{/symbol Z}";

    constexpr auto SYMBOL_ALEPH                 = "{/symbol \\300}";
    constexpr auto SYMBOL_REAL_PART             = "{/symbol \\302}";
    constexpr auto SYMBOL_IMAGINARY_PART        = "{/symbol \\301}";

    constexpr auto SYMBOL_LESS_OR_EQUAL         = "{/symbol \\243}";
    constexpr auto SYMBOL_GREATER_OR_EQUAL      = "{/symbol \\263}";
    constexpr auto SYMBOL_APPROXIMATELY         = "{/symbol \\273}";
    constexpr auto SYMBOL_NOT_EQUAL             = "{/symbol \\271}";
    constexpr auto SYMBOL_PROPORTIONAL          = "{/symbol \\265}";
    constexpr auto SYMBOL_PLUSMINUS             = "{/symbol \\261}";
    constexpr auto SYMBOL_SQUAREROOT            = "{/symbol \\326}";
    constexpr auto SYMBOL_DOT                   = "{\\267}";
    constexpr auto SYMBOL_TIMES                 = "{/symbol \\264}";
    constexpr auto SYMBOL_DIVISION              = "{/symbol \\270}";
    constexpr auto SYMBOL_PARTIAL_DERIVATIVE    = "{/symbol \\266}";
    constexpr auto SYMBOL_INTEGRAL              = "{/symbol \\362}";
    constexpr auto SYMBOL_NABLA                 = "{/symbol \\321}";
    constexpr auto SYMBOL_OTIMES                = "{/symbol \\304}";
    constexpr auto SYMBOL_OPLUS                 = "{/symbol \\305}";

    constexpr auto SYMBOL_ELEMENT               = "{/symbol \\316}";
    constexpr auto SYMBOL_NOT_ELEMENT           = "{/symbol \\317}";
    constexpr auto SYMBOL_FORALL                = "{/symbol \\042}";
    constexpr auto SYMBOL_EXISTS                = "{/symbol \\044}";

    constexpr auto SYMBOL_AT                    = "{\\100}";
    constexpr auto SYMBOL_FORWARD_SLASH         = "{\\057}";
    constexpr auto SYMBOL_BACKWARD_SLASH        = "{\\134}";
    constexpr auto SYMBOL_CURLY_BRACE_OPEN      = "{\\173}";
    constexpr auto SYMBOL_CURLY_BRACE_CLOSE     = "{\\175}";
    constexpr auto SYMBOL_AMPERSAND             = "{\\046}";
    constexpr auto SYMBOL_TILDE                 = "{\\176}";
    constexpr auto SYMBOL_CARET                 = "{\\136}";
    constexpr auto SYMBOL_UNDERSCORE            = "{\\137}";
    constexpr auto SYMBOL_EURO                  = "{/symbol \\240}";
    constexpr auto SYMBOL_INFINITY              = "{/symbol \\245}";
    constexpr auto SYMBOL_DEGREE                = "{/symbol \\260}";
    //! @todo test this
    constexpr auto SYMBOL_HBAR                  = "{\\U+210F}"; //"ħ"

    constexpr auto SYMBOL_CLUB                  = "{/symbol \\247}";
    constexpr auto SYMBOL_SPADES                = "{/symbol \\250}";
    constexpr auto SYMBOL_HEARTS                = "{/symbol \\241}";
    constexpr auto SYMBOL_DIAMONDS              = "{/symbol \\242}";

    constexpr auto SYMBOL_ARROW_LEFTRIGHT       = "{/symbol \\253}";
    constexpr auto SYMBOL_ARROW_LEFT            = "{/symbol \\254}";
    constexpr auto SYMBOL_ARROW_UP              = "{/symbol \\255}";
    constexpr auto SYMBOL_ARROW_RIGHT           = "{/symbol \\256}";
    constexpr auto SYMBOL_ARROW_DOWN            = "{/symbol \\257}";

    constexpr auto SYMBOL_CHECKED               = "{/zapfdingbats 3}";
    constexpr auto SYMBOL_CROSSED               = "{/zapfdingbats 7}";
    constexpr auto SYMBOL_BOX                   = "{/zapfdingbats p}";
    constexpr auto SYMBOL_CHECKED_BOX           = "{/zapfdingbats @p3}";
    constexpr auto SYMBOL_CROSSED_BOX           = "{/zapfdingbats @p7}";
}

#endif // CONSTANTS_H
