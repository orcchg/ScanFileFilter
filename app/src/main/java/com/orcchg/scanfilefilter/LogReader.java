package com.orcchg.scanfilefilter;

public class LogReader {

    static {
        System.loadLibrary("logreader");
    }

    private static LogReader instance;

    public static LogReader getInstance() {
        if (instance == null) {
            synchronized (LogReader.class) {
                if (instance == null) {
                    instance = new LogReader();
                }
            }
        }
        return instance;
    }

    public native boolean setFilter(String filter);
    public native boolean addSourceBlock(String block);
}
