class Fork {
    enum State {
        DIRTY, CLEAN
    };

    private State state;
    private long ownerId;

    public Fork(long ownerId) {
        state = State.DIRTY;
        this.ownerId = ownerId;
    }

    public synchronized void request(long id) {
        while (ownerId != id) {
            if (state == State.DIRTY) {
                ownerId = id;
                state = State.CLEAN;
            } else {
                try {
                    wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public synchronized void release() {
        state = State.DIRTY;
        notifyAll();
    }

}