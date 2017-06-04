#include "Main.h"

void Gui::onLoadFromFilePressed(tgui::EditBox::Ptr editbox)
{
	if (editbox->getText() == "File name")
	{
		editbox->setText("");
	}
}