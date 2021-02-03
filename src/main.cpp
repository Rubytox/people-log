#include <iostream>

#include <Person>
#include <SocialNetworks>

using namespace std;

int main(int argc, char *argv[])
{
    Person me("Christophe", "Néraud", "28/04/2000", "Bakou (Azerbaidjan)", "path/to/picture");
    me.addSocialNetwork(TWITTER, "@rubytox");
    me.addSocialNetwork(TWITTER, "@rubytox2");
    me.addSocialNetwork(FACEBOOK, "cneraud");
    me.display();

    return 0;
}
