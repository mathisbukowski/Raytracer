/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** 04
*/

#ifndef SCENEPARSER_HPP
#define SCENEPARSER_HPP

#include <libconfig.h++>
#include <memory>
#include <iostream>
#include <utility>

#include "Scene/Camera.hpp"
#include "Scene/Scene.hpp"

namespace RayTracer {
    /**
     * @class SceneParser
     * @note Have to parse the file passed in parameters. And return all infos needed by the project
     */
    class SceneParser {
    public:
        /**
         * @class SceneParserError
         * @note Handle all errors in the SceneParser Class
         */
        class SceneParserError : public std::exception {
        public:
            /**
             * Constructor of the class SceneParserError
             * @param message message to throw
             */
            explicit SceneParserError(std::string  message): _message(std::move(message)) {}
            /**
             * Return the message to throw
             * @return std::string
             */
            [[nodiscard]] const char* what() const noexcept override { return _message.c_str(); }
        private:
            std::string _message; ///< Message to throw
        };

        /**
         * Constructor of the class SceneParser
         * @param
         */
        SceneParser(const std::string& sceneFile, const std::shared_ptr<Scene>& scene);

        /**
         * Initialize the primitives of the scene
         * @note This function will parse the scene file and create the primitives
         */
        void initializePrimitives();

        /**
         * Get the scene root
         * @note This function will return the root of the scene
         * @return std::shared_ptr<libconfig::Setting>
         */
        [[nodiscard]] libconfig::Setting& getSceneRoot() const;

        /**
         * Safe lookup function
         * @note This function will catch all exceptions and throw a SceneParserError
         * @param functionToLookUp function to look up
         * @tparam Func function type
         */
        template<typename Func>
        void safeLookup(Func functionToLookUp) {
            try {
                functionToLookUp();
            } catch (const libconfig::SettingNotFoundException& e) {
                throw SceneParserError(std::string("Setting not found: ") + e.what());
            } catch (const libconfig::SettingTypeException& e) {
                throw SceneParserError(std::string("Type error: ") + e.what());
            } catch (const libconfig::ParseException& e) {
                throw SceneParserError(std::string("Parse error at ") + e.getFile() + ":" + std::to_string(e.getLine()) + " - " + e.getError());
            } catch (const std::exception& e) {
                throw SceneParserError(std::string("Error: ") + e.what());
            }
        }
        /**
         * @class CameraConfig
         * @note Handle all camera configuration
         */
        class CameraConfig {
        public:
            int width;
            int height;
            float rx, ry, rz;
            float fov;
            float px, py, pz;
        };

        /**
         * Initialize the camera of the scene
         * @note This function will parse the scene file and create the camera
         * @return Camera
         */
        Camera initializeCamera();

        /**
         * Initialize the lights of the scene
         * @note This function will parse the scene file and create the lights
         */
        void initializeLights();

    private:
        std::shared_ptr<Scene> _scene = nullptr; ///< Scene of the raytracer
        std::unique_ptr<libconfig::Config> _config = nullptr; ///< Scene Config with the libconfig++
    };
};



#endif //SCENEPARSER_HPP
