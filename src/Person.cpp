//
// Created by rubytox on 02/02/2021.
//

#include "../includes/Person"

#include <utility>

using namespace std;

Person::Person(string firstName, string lastName, string dateOfBirth,
               string placeOfBirth, string picture) : WeakPerson(std::move(firstName), std::move(lastName)),
                                                      _dateOfBirth(std::move(dateOfBirth)), _placeOfBirth(std::move(placeOfBirth)),
                                                      _picture(std::move(picture))
{
    for (int level = 0; level != NB_FRIENDSLEVEL; level++) {
        auto lvl = static_cast<FriendsLevel>(level);
        _friends[lvl] = vector<WeakPerson>();
    }
    for (int social = 0; social != NB_NETWORKS; social++) {
        auto network = static_cast<SocialNetwork>(social);
        _socialNetworks[network] = vector<string>();
    }
}

void Person::addPicture(const string &picture)
{
    _pictures.push_back(picture);
}

void Person::addPicture(const std::vector<std::string> &pictures)
{
    _pictures.insert(end(_pictures), begin(pictures), end(pictures));
}

void Person::addSocialNetwork(const SocialNetwork &socialNetwork, const string &id)
{
    _socialNetworks[socialNetwork].push_back(id);
}

void Person::display() {
    cout << "" << _lastName << " " << _firstName << endl;
    cout << "Born " << _dateOfBirth << " in " << _placeOfBirth << endl;
    cout << "Twitter accounts:" << endl;
    for (const auto& account: _socialNetworks[TWITTER]) {
        cout << "\t- " << account << endl;
    }
}

WeakPerson::WeakPerson() = default;

WeakPerson::WeakPerson(std::string firstName, std::string lastName) : _firstName(std::move(firstName)), _lastName(std::move(lastName))
{}
