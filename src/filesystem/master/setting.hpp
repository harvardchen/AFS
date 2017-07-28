//
// Created by Aaron Ren on 28/07/2017.
//

#ifndef AFS_SETTING_HPP
#define AFS_SETTING_HPP

#include "extrie.hpp"
#include "common.h"
#include <string>
#include <mutex>
#include <thread>
#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/lock_types.hpp>

// alias
namespace AFS {

using Address = std::string;
using std::size_t;
using std::time_t;
using readWriteMutex = boost::shared_mutex;
using readLock = boost::shared_lock<boost::shared_mutex>;
using writeLock = std::unique_lock<boost::shared_mutex>;

}

// Error
namespace AFS {

enum class MasterError {
	OK, NotExists, PermissonDenied,
	Unknown
};

class ErrTranslator {
public:
	static MasterError extrieErrToMasterErr(const ExtrieError & err) {
		switch ((int)err) {
			case (int)ExtrieError::OK:
				return MasterError::OK;
			case (int)ExtrieError::NotExist:
				return MasterError::NotExists;
			default:
				break;
		}
		return MasterError::Unknown;
	}

	static GFSErrorCode masterErrTOGFSError(MasterError err) {
		switch((int)err) {
			case (int)MasterError::OK:
				return GFSErrorCode::OK;
			default:
				break;
		}
		return GFSErrorCode::Unknown;
	}
};

}
#endif //AFS_SETTING_HPP