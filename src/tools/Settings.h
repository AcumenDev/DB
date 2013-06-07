#ifndef SETTINGS_H
#define SETTINGS_H
#include <memory>
namespace Core {
class Settings
{
    public:

        virtual ~Settings();
         static std::shared_ptr<Settings>  GetSettings();

    protected:
    private:

          static     std::shared_ptr<Settings>  _Settings;
          Settings();
};
}
#endif // SETTINGS_H
