//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::AddButtonClick(TObject *Sender)
{
	// if the user clicks on the "Add" button, add the text to the list box

	// event 1: if the edit box is empty, do nothing
	if (TaskEdit->Text == "") return;

	// event 2: if the edit box is not empty, add the text to the list box
	String taskText=TaskEdit->Text;
	TaskListBox->Items->Add(taskText);

	// event 3: clear the edit box after adding the text
    TaskEdit->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TaskListBoxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)

{
	// if the user clicks on the list box, delete the selected item

	// event 1: if the list box is empty, do nothing
	if (TaskListBox->Items->Count == 0) return;

	// event 2: if the list box is not empty, delete the selected item
	int index = Item->Index;
	TaskListBox->Items->Delete(index);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
		  TShiftState Shift)
{
	// if the user presses the "Enter" key, add the text to the list box

	// event 1: "Enter key" is pressed and the edit box is empty, do nothing
	if (Key == vkReturn && TaskEdit->Text == "") return;

	// event 2: "Enter key" is pressed and the edit box is not empty, add the text to the list box
	if (Key == vkReturn) AddButtonClick(Sender);

	// event 3: clear the edit box after adding the text
	TaskEdit->Text="";

}
//---------------------------------------------------------------------------

