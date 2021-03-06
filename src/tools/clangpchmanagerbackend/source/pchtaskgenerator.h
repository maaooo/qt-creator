/****************************************************************************
**
** Copyright (C) 2018 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#include "pchtask.h"
#include "pchtaskgeneratorinterface.h"

#include <projectpartcontainer.h>

namespace ClangBackEnd {

class PchTasksMergerInterface;

class BuildDependenciesProviderInterface;
class ProgressCounter;

class PchTaskGenerator : public PchTaskGeneratorInterface
{
public:
    PchTaskGenerator(BuildDependenciesProviderInterface &buildDependenciesProvider,
                     PchTasksMergerInterface &pchTasksMergerInterface,
                     ProgressCounter &progressCounter)
        : m_buildDependenciesProvider(buildDependenciesProvider)
        , m_pchTasksMergerInterface(pchTasksMergerInterface)
        , m_progressCounter(progressCounter)

    {}

    void addProjectParts(ProjectPartContainers &&projectParts,
                         Utils::SmallStringVector &&toolChainArguments) override;
    void removeProjectParts(const ProjectPartIds &projectsPartIds) override;

private:
    BuildDependenciesProviderInterface &m_buildDependenciesProvider;
    PchTasksMergerInterface &m_pchTasksMergerInterface;
    ProgressCounter &m_progressCounter;
};

} // namespace ClangBackEnd
