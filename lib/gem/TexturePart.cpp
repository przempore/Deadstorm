#include "gem/TexturePart.hpp"

#include "gem/Content.hpp"
#include "gem/Error.hpp"
#include "gem/Texture.hpp"

#include "pugixml/pugixml.hpp"

#include <boost/lexical_cast.hpp>

using namespace boost;
using namespace pugi;
using namespace std;

namespace Gem
{
    AssetPtr TexturePart::Load(const std::string &path,
                               bool cache)
    {
        xml_document doc;

        printf("file: %s, path: %s\n", __FILE__, path.c_str());

        xml_parse_result result{doc.load_file(path.c_str())};

        if (!result)
        {
            throw Error{"error while parsing texture part asset definition"};
        }
        printf("file: %s, texture-part: %s\n", __FILE__,
               string(doc.child("texture-part").attribute("texture").value()).c_str());
        string texPath = doc.child("texture-part").attribute("path").value();
        string file = doc.child("texture-part").attribute("texture").value();
        printf("file: %s, path: %s\n", __FILE__, string(doc.child("texture-part").attribute("path").value()).c_str());

        TexturePtr texture{
                g_content.Acquire<Gem::Texture>(texPath + file/*string(doc.child("texture-part").attribute("texture").value())*/,
                                                cache)};

        printf("file: %s, wymiary: %d, %d, %d, %d\n", __FILE__,
               lexical_cast<int>(doc.child("texture-part").attribute("x").value()),
               lexical_cast<int>(doc.child("texture-part").attribute("y").value()),
               lexical_cast<int>(doc.child("texture-part").attribute("w").value()),
               lexical_cast<int>(doc.child("texture-part").attribute("h").value()));

        Rectangle sourceRectangle{lexical_cast<int>(doc.child("texture-part").attribute("x").value()),
                                  lexical_cast<int>(doc.child("texture-part").attribute("y").value()),
                                  lexical_cast<int>(doc.child("texture-part").attribute("w").value()),
                                  lexical_cast<int>(doc.child("texture-part").attribute("h").value())};

        return AssetPtr{new TexturePart{texture,
                                        sourceRectangle}};
    }
}
