#include <iostream>
#include <vector>
using namespace std;

// three layers: Receiver or underlying business logic, user interface or Invoker and command interface to connect the two

// Command Interface: Action Interface
class CommandInterface {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~CommandInterface() {}
};

// Receiver - Executes the actual operation (e.g., modifying the text).
class Editor {
public:
    void open() { cout << "Editor Opened" << endl; }
    void save() { cout << "Editor Saved" << endl; }
};

// Concrete Command: creates binding between action and receiver
class CommandOpen : public CommandInterface {
private:
    Editor* doc;
public:
    CommandOpen(Editor* document) : doc(document) {}
    void execute() override { doc->open(); }
};

class CommandSave : public CommandInterface {
private:
    Editor* doc;
public:
    CommandSave(Editor* document) : doc(document) {}
    void execute() override { doc->save(); }
};

// Invoker: Invokes the command and maintains a history of executed commands.
class MenuOptions {
private:
    vector<CommandInterface*> commands;

public:
    void addCommand(CommandInterface* command) { commands.push_back(command); }

    void executeCommands() {
        for (CommandInterface* command : commands) {
            command->execute();
        }
    }
    void undoCommand(){

    }
};


// Client: Create concrete command and associate with the receiver
int main() {
    Editor doc;
    MenuOptions menu;

    //mapping operations to the buttons
    CommandInterface* clickOpen = new CommandOpen(&doc);
    CommandInterface* clickSave = new CommandSave(&doc);

    // entering commands to execute
    menu.addCommand(clickOpen);
    menu.addCommand(clickSave);
    
    // Client code only adds commands to the menu
    // The invoker (menu) doesn't need to change when new commands are added
    menu.executeCommands();

    delete clickOpen;
    delete clickSave;

    return 0;
}
