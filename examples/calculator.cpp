#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/place.hpp>

using namespace nana;

struct stateinfo
{
    enum class state{init, operated, assigned};

    state   opstate{state::init};
    wchar_t operation{L'+'};
    double oprand{0};
    double outcome{0};
    label & procedure;
    label & result;

    stateinfo(label& proc, label& resl)
        : procedure(proc), result(resl)
    {}
};

//Omit the definitons at this point.
//Full definitions in calculator.cpp
//handle the number keys
void numkey_pressed(stateinfo& state, const arg_mouse& arg);

//handle the non-number keys
void opkey_pressed(stateinfo& state, const arg_mouse& arg);

int main()
{
    form fm;
    fm.caption(STR("Calculator"));

    //Use class place to layout the widgets.
    place place(fm);
    place.div(  "vert<procedure weight=10%><result weight=15%>"
        "<weight=2><opkeys margin=2 grid=[4, 5] gap=2 collapse(0,4,2,1)>");

    label procedure(fm), result(fm);

    //Make the label right aligned.
    procedure.text_align(nana::align::right);
    result.text_align(nana::align::right);
    result.typeface(nana::paint::font(nullptr, 14, true));

    place.field("procedure")<<procedure;
    place.field("result")<<result;

    stateinfo state(procedure, result);
    std::vector<std::unique_ptr<nana::button>> op_keys;

    wchar_t keys[] = L"C\261%/789X456-123+0.=";
    nana::paint::font keyfont(nullptr, 10, true);
    for(auto key : keys)
    {
        op_keys.emplace_back(new button(fm));
        op_keys.back()->caption(string(1, key));
        op_keys.back()->typeface(keyfont);

        if('=' == key)
        {
            op_keys.back()->bgcolor(color_rgb(0x7ACC));
            op_keys.back()->fgcolor(color_rgb(0xFFFFFF));
        }
        place.field("opkeys") << *op_keys.back();

        //Make event answer for keys.
//        if(('0' <= key && key <= '9') || ('.' == key))
//            op_keys.back()->events().click.connect(std::bind(numkey_pressed, std::ref(state), std::placeholders::_1));
//        else
//            op_keys.back()->events().click.connect(std::bind(opkey_pressed, std::ref(state), std::placeholders::_1));
    }

    place.collocate();
    fm.show();
    exec();
}
