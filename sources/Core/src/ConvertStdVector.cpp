/*
 * Copyright (C) 2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * GNU Lesser General Public License v2.1 or any later version.
 */

#include "BlockFactory/Core/ConvertStdVector.h"
#include <algorithm>

// Template definition
// ===================

template <typename Tin, typename Tout>
void blockfactory::core::convertStdVector(const std::vector<Tin>& input, std::vector<Tout>& output)
{
    output = std::vector<Tout>(input.begin(), input.end());
}

// Explicit instantiation for all the other supported types
// ========================================================

template void blockfactory::core::convertStdVector<int, int>(const std::vector<int>& input,
                                                             std::vector<int>& output);
template void blockfactory::core::convertStdVector<int, bool>(const std::vector<int>& input,
                                                              std::vector<bool>& output);
template void blockfactory::core::convertStdVector<int, double>(const std::vector<int>& input,
                                                                std::vector<double>& output);
// Bool to other numeric types
template void blockfactory::core::convertStdVector<bool, bool>(const std::vector<bool>& input,
                                                               std::vector<bool>& output);
template void blockfactory::core::convertStdVector<bool, int>(const std::vector<bool>& input,
                                                              std::vector<int>& output);
template void blockfactory::core::convertStdVector<bool, double>(const std::vector<bool>& input,
                                                                 std::vector<double>& output);
// Double to other numeric types
template void blockfactory::core::convertStdVector<double, double>(const std::vector<double>& input,
                                                                   std::vector<double>& output);
template void blockfactory::core::convertStdVector<double, int>(const std::vector<double>& input,
                                                                std::vector<int>& output);
template void blockfactory::core::convertStdVector<double, bool>(const std::vector<double>& input,
                                                                 std::vector<bool>& output);
// String to string
template void blockfactory::core::convertStdVector<std::string, std::string>(
    const std::vector<std::string>& input,
    std::vector<std::string>& output);

// Explicit specialization for std::string type
// ============================================

template <>
void blockfactory::core::convertStdVector<std::string, int>(const std::vector<std::string>& input,
                                                            std::vector<int>& output)
{
    output.clear();
    output.resize(input.size());
    std::transform(input.begin(), input.end(), output.begin(), [](const std::string& str) {
        return std::stoi(str);
    });
}

template <>
void blockfactory::core::convertStdVector<std::string, bool>(const std::vector<std::string>& input,
                                                             std::vector<bool>& output)
{
    output.clear();
    output.resize(input.size());
    std::transform(input.begin(), input.end(), output.begin(), [](const std::string& str) {
        return static_cast<bool>(std::stoi(str));
    });
}

template <>
void blockfactory::core::convertStdVector<std::string, double>(
    const std::vector<std::string>& input,
    std::vector<double>& output)
{
    output.clear();
    output.resize(input.size());
    std::transform(input.begin(), input.end(), output.begin(), [](const std::string& str) {
        return std::stod(str);
    });
}

template <>
void blockfactory::core::convertStdVector<int, std::string>(const std::vector<int>& input,
                                                            std::vector<std::string>& output)
{
    output.clear();
    output.resize(input.size());
    std::transform(input.begin(), input.end(), output.begin(), [](const int& num) {
        return std::to_string(num);
    });
}

template <>
void blockfactory::core::convertStdVector<bool, std::string>(const std::vector<bool>& input,
                                                             std::vector<std::string>& output)
{
    output.clear();
    output.resize(input.size());
    std::transform(input.begin(), input.end(), output.begin(), [](const bool& num) {
        return std::to_string(num);
    });
}

template <>
void blockfactory::core::convertStdVector<double, std::string>(const std::vector<double>& input,
                                                               std::vector<std::string>& output)
{
    output.clear();
    output.resize(input.size());
    std::transform(input.begin(), input.end(), output.begin(), [](const double& num) {
        return std::to_string(num);
    });
}
