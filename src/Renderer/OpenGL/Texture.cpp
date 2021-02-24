#include "Texture.h"

Texture::Texture(const char* texturePath, int textureUnit)
{
    stbi_set_flip_vertically_on_load(1);

    glGenTextures(1, &m_Texture);
    glActiveTexture(textureUnit);
    glBindTexture(GL_TEXTURE_2D, m_Texture);

    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //for jpeg, if width is not a multiple of 4 it doesn't work properly
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // load and generate the texture
    int width, height, nrChannels;

    unsigned char* data = stbi_load(texturePath, &width, &height, &nrChannels, 0);

    if (data)
    {
        if (JPG_CHANNEL == nrChannels)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        }
        else
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        }

        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }

    stbi_image_free(data);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    stbi_set_flip_vertically_on_load(0);
}