/* Copyright 2013-2015 MultiMC Contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <launch/LaunchStep.h>
#include <QObjectPtr.h>
#include <launch/LoggedProcess.h>
#include <java/JavaChecker.h>

#include "multimc_logic_export.h"

class MULTIMC_LOGIC_EXPORT Update: public LaunchStep
{
	Q_OBJECT
public:
	explicit Update(LaunchTask *parent):LaunchStep(parent) {};
	virtual ~Update() {};

	void executeTask() override;
	bool canAbort() const override;
	void proceed() override;
public slots:
	bool abort() override;

private slots:
	void updateFinished();

private:
	shared_qobject_ptr<Task> m_updateTask;
	bool m_aborted = false;
};
