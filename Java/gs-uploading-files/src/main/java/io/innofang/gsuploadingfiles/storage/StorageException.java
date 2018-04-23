package io.innofang.gsuploadingfiles.storage;

/**
 * Created by Inno Fang on 2018/4/23.
 */
public class StorageException extends RuntimeException {
    public StorageException(String message) {
        super(message);
    }

    public StorageException(String message, Throwable cause) {
        super(message, cause);
    }
}
